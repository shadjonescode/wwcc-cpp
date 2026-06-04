#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Student {
    string lastName;
    string firstName;
    int g1, g2, g3;
    double average;
    int high;
    int low;
};

int main() {
    // --- Read input file ---
    ifstream inFile("grades.txt");

    // BUG: Program opens the file but never checks if it opened successfully.
    // FIX: Verify the file opened before attempting to read from it.
    if (!inFile){
        cout << "ERROR: Could not open grades.txt" << endl;
        return 1;
    }
    cout << "Reading records from grades.txt..." << endl;

    vector<Student> students;
    string line;

    // BUG: Using !inFile.eof() can cause the last record to be processed twice.
    // FIX: Use getline() as the loop condition so the loop only runs when a line is successfully read.
    while (getline(inFile, line)){

        if (line.empty() || line[0] == '#') continue;

        // BUG: Reusing the same stringstream across multiple line can leave it in a failed state and cause incorrect parsing.
        // FIX: Create a new stringstream for each line being processed.
         stringstream ss(line);

        Student s;
        ss >> s.lastName >> s.firstName >> s.g1 >> s.g2 >> s.g3;

        s.high = max({s.g1, s.g2, s.g3});
        s.low  = min({s.g1, s.g2, s.g3});

        int total = s.g1 + s.g2 + s.g3;

        // BUG: Integer division truncates the decimal portion of the average.
        // FIX: Divide by 3.0 so floating-point division is used.
        s.average = total / 3.0;    // Bug 5 is here

        students.push_back(s);
    }  // placeholder: real parsing below
    
        // BUG: stringstream is reused between iterations, causing parsing state to carry over.
        // FIX: Create a new stringstream for each line processed.

    inFile.close();

    cout << students.size() << " students loaded." << endl << endl;

    // BUG: Opening the output file normally overwrites previous report data.
    // FIX: Open the file in append mode so new reports are added at the end.
    ofstream outFile("grade_report.txt", ios::app);   // Bug 3 is here

    // --- Display to console and write to file ---
    auto printReport = [&](ostream& out) {
        out << "GRADE REPORT" << endl;
        out << string(20, '-') << endl;

        out << left 
            << setw(20) << "Name"
            << setw(7)  << "Avg"
            << setw(7)  << "High"
            << setw(7)  << "Low"
            << endl;
        out << string(20, '-') << endl;

        double classTotal = 0;
        int topIdx = 0, lowIdx = 0;

        // Bug 6: setw is applied once here, outside the loop

        for (int i = 0; i < (int)students.size(); i++) {
            Student& s = students[i];
            string name = s.lastName + ", " + s.firstName;

            // Bug 7: numbers should be right-aligned, not left
            // BUG: setw() was applied once before the loop, so it only affected the next output.
            // FIX: Apply setw(20) to the name field inside each row.

            // BUG: Numeric columns were left-alligned, making the report formatting wrong.
            // FIX: Keep names left-alligned, then switch numbers to right alligned
            out << left << setw(20) << name
                << right << setw(7)  << fixed << setprecision(1) << s.average
                << setw(7)  << s.high
                << setw(7)  << s.low
                << endl;

            classTotal += s.average;
            if (s.average > students[topIdx].average) topIdx = i;
            if (s.average < students[lowIdx].average) lowIdx = i;
        }

        double classAvg = classTotal / students.size();

        out << endl << "CLASS STATISTICS" << endl;
        out << string(20, '-') << endl;
        out << fixed << setprecision(1);
        out << "Class average: " << classAvg << endl;
        out << "Top student:   "
            << students[topIdx].lastName << ", "
            << students[topIdx].firstName
            << " (" << students[topIdx].average << ")" << endl;
        out << "Low student:   "
            << students[lowIdx].lastName << ", "
            << students[lowIdx].firstName
            << " (" << students[lowIdx].average << ")" << endl;
    };

    printReport(cout);
    printReport(outFile);
    outFile.close();

    cout << endl << "Report written to grade_report.txt" << endl;
    return 0;
}