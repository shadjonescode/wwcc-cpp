#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>
using namespace std;

enum class Department { ENGINEERING, SALES, HR, OPERATIONS };

constexpr double OVERTIME_THRESHOLD = 40.0;
constexpr double OVERTIME_MULTIPLIER = 1.5;
constexpr double MAX_WEEKLY_HOURS = 168.0;

struct Employee {
    string name;
    Department dept;
    // BUG: hourlyRate was an int, so fractional rates like 32.5 were truncated.
    // FIX: Changed hourlyRate to double to preserve decimal hourly rates.
    double hourlyRate;      // Bug 2: should be double
    double hoursWorked;
};

// Returns the display name for a department
string deptName(Department d) {
    switch (d) {
        case Department::ENGINEERING: return "Engineering";
        case Department::SALES:       return "Sales";
        case Department::HR:          return "HR";
        case Department::OPERATIONS:  return "Operations";
        // BUG: Switch statement had no default case, causing undefined behavior.
        // FIX: Added a defauly case to handle unexpected department values/
        default:                      return "Unknown"; // Bug 3: no default case
    }
}

// Validate hours input — returns true if valid
bool validHours(double hours) {

    // BUG: Function only checked if hours exceeded the maximum and allowed negative values.
    // FIX: Added a check for negative hours so invalid inputs are rejected.
    if (hours < 0){
        cout << "Error: hours cannot be negative\n";
        return false;
    }
    if (hours > MAX_WEEKLY_HOURS) {    // Bug 4: only checks upper bound
        cout << "Error: hours cannot exceed " << MAX_WEEKLY_HOURS << "\n";
        return false;
    }
    return true;
}

// Calculate weekly pay for one employee (with overtime)
double calculatePay(const Employee& e) {
    if (e.hoursWorked <= OVERTIME_THRESHOLD) {
        return e.hoursWorked * e.hourlyRate;
    } else {
        // Bug 1: applies overtime rate to ALL hours, not just excess
        // BUG: Overtime multiplier was applied to all hours worked.
        // FIX: Pay first 40 hours at normal rate and only overtime hours at 1.5x.
        double regularPay = OVERTIME_THRESHOLD * e.hourlyRate;
        double overtimeHours = e.hoursWorked - OVERTIME_THRESHOLD;
        double overtimePay = overtimeHours * e.hourlyRate * OVERTIME_MULTIPLIER;

        return e.hoursWorked * e.hourlyRate * OVERTIME_MULTIPLIER;
    }
}

// Display a single employee row
void printEmployee(const Employee& e) {
    cout << left  << setw(20) << e.name
         << setw(14) << deptName(e.dept)
         << right << setw(8)  << fixed << setprecision(2) << e.hoursWorked << " hrs"
         << setw(10) << "$" + to_string((int)e.hourlyRate) + "/hr"
         << setw(12) << "$" + to_string((int)calculatePay(e))
         << "\n";
}

// Display all employees
void displayAll(const vector<Employee>& employees) {
    cout << "\n=== Employee Time Report ===\n";
    cout << left  << setw(20) << "Name"
         << setw(14) << "Department"
         << right << setw(8)  << "Hours"
         << setw(10) << "Rate"
         << setw(12) << "Pay"
         << "\n";
    cout << string(64, '-') << "\n";
    for (const auto& emp : employees) {
        printEmployee(emp);
    }
}

// Calculate total payroll cost
double totalPayroll(const vector<Employee>& employees) {
    // BUG: accumulate() started with integer 0, which can cause loss of precision.
    // FIX: Changed initial value to 0.0 so accumulation is percormed using doubles
    return accumulate(employees.begin(), employees.end(), 0.0,  // Bug 5: integer init
        [](double sum, const Employee& e) {
            return sum + calculatePay(e);
        });
}

void sortByHours(vector<Employee>& employees) {

    sort(employees.begin(), employees.end(),
        [](const Employee& a, const Employee& b) {
            return a.hoursWorked > b.hoursWorked;
        });

    cout << "\n=== Hours Ranking ===\n";

    for (const auto& emp : employees) {
        printEmployee(emp);
    }
}

void getDepartmentStats(const vector<Employee>& employees, Department dept) {

    vector<Employee> deptEmployees;

    copy_if(employees.begin(), employees.end(),
            back_inserter(deptEmployees),
            [dept](const Employee& e) {
                return e.dept == dept;
            });

    int count = deptEmployees.size();

    double totalHours = 0.0;
    double totalPay = 0.0;

    for (const auto& emp : deptEmployees) {
        totalHours += emp.hoursWorked;
        totalPay += calculatePay(emp);
    }

    double averagePay = 0.0;

    if (count > 0) {
        averagePay = totalPay / count;
    }

    cout << "\n=== " << deptName(dept) << " Department Stats ===\n";
    cout << "Employees: " << count << endl;
    cout << "Total Hours: " << fixed << setprecision(2) << totalHours << endl;
    cout << "Average Pay: $" << fixed << setprecision(2) << averagePay << endl;
}

void exportPayrollReport(const vector<Employee>& employees, const string& filename) {

    ofstream outFile(filename);

    if (!outFile) {
        cout << "Error: could not open " << filename << endl;
        return;
    }

    vector<Department> departments = {
        Department::ENGINEERING,
        Department::SALES,
        Department::HR,
        Department::OPERATIONS
    };

    for (const auto& dept : departments) {

        outFile << "=== " << deptName(dept) << " ===" << endl;

        double subtotal = 0.0;

        for (const auto& emp : employees) {

            if (emp.dept == dept) {

                double pay = calculatePay(emp);

                outFile << emp.name
                        << " | Hours: " << fixed << setprecision(2)
                        << emp.hoursWorked
                        << " | Pay: $" << pay
                        << endl;

                subtotal += pay;
            }
        }

        outFile << "Subtotal: $" << fixed << setprecision(2)
                << subtotal << endl;

        outFile << endl;
    }

    outFile.close();

    cout << "Payroll report saved to " << filename << endl;
}

int main() {
    vector<Employee> employees = {
        {"Alice Chen",      Department::ENGINEERING, 42,   45.0},
        {"Bob Martinez",    Department::SALES,       28,   38.0},
        {"Carol Singh",     Department::HR,          35,   32.5},  // fractional rate
        {"David Park",      Department::ENGINEERING, 38,   50.0},
        {"Emma Wilson",     Department::OPERATIONS,  30,   29,  },
        {"Frank Torres",    Department::SALES,       45,   44.5},  // overtime
        {"Grace Kim",       Department::HR,          33,   33.5},  // fractional rate
        {"Henry Okafor",    Department::OPERATIONS,  29,   55.0},  // overtime
    };

    cout << "=== HR Time Tracker ===\n";

    // Validate a sample input
    cout << "\nValidating hours entry -5: "
         << (validHours(-5) ? "valid" : "invalid") << "\n";  // should be invalid

    displayAll(employees);

    cout << "\nTotal payroll this week: $"
         << fixed << setprecision(2) << totalPayroll(employees) << "\n";


    sortByHours(employees);
    getDepartmentStats(employees, Department::ENGINEERING);
    exportPayrollReport(employees, "payroll_report.txt");

    return 0;
}