#include <iostream>
#include <string>
using namespace std;

// A class for managing a bank account
class account {
// Made the data private.
private:
    string customerName;
    double balance;
    bool isOpen;
    int accountNumber;
    string accountType;
// Interest rates were random. I stored the rates as constants.
    const double SAVINGS_INTEREST_RATE = 1.03;
    const double CHECKING_INTEREST_RATE = 1.01;
    const double BUSINESS_INTEREST_RATE = 1.005;
public:
    account(string name, int number, string type){
        customerName = name;
        accountNumber = number;
        balance = 0;
        isOpen = true;

        if (type == "savings" || type == "checking" || type == "business"){
            accountType = type;
        } else {
            accountType = "checking";
            cout << "Invalid account type. Defaulting to checking." << endl;
        }
    }
    void deposit(double amount){
// Fixed issue where deposits worked even if account was closed.
        if (!isOpen){
            cout << "Cannot deposit. Account is closed." << endl;
            return;
        }
// Fixed issue where you could deposit 0 or negative amounts
        if (amount <= 0){
            cout << "Deposit amount must be greater than 0" << endl;
            return;
        }
        balance += amount;
    }

    void withdraw(double amount){
// Fixed issue where withdrawls would work with closed accounts.
        if (!isOpen){
            cout << "Cannot withdraw. Account is closed." << endl;
            return;
        }
        if (amount <= 0){
            cout << "Withdrawal amount must be greater than 0." << endl;
            return;
        }
// Fixed an issue where wihdrawals could make balance negative.
        if (amount > balance){
            cout << "Insufficient funds." << endl;
            return;
        }
        balance -= amount;
    }
// Fixed issue of interest being added to closed accounts.
    void addInterest(){
        if (!isOpen){
            cout << "Cannot add interest. Account is closed." << endl;
            return;
        }
        if (accountType == "savings"){
            balance *= SAVINGS_INTEREST_RATE;
        } else if (accountType == "checking"){
            balance *= CHECKING_INTEREST_RATE;
        } else if (accountType ==  "business"){
            balance *= BUSINESS_INTEREST_RATE;
        }
    }

    void print() const{
        cout << "Account Number: " << accountNumber << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Status " << (isOpen ? "open" : "closed") << endl;
    }
    void close(){
        isOpen = false;
    }

    double getBalance() const{
        return balance;
    }
};

int main(){
    account acc1("John Smith", 12345, "savings");
    acc1.deposit(1000);
    acc1.withdraw(250);
    acc1.addInterest();

    acc1.print();
    acc1.close();

    return 0;
}