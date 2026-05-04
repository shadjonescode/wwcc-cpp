#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Struct used to store account information and transaction history
struct Account {
  int accountNumber;
  string holderName;
  double balance;
  double transactionHistory[100];
  int transactionCount;
};

void displayMenu();

int main() {
  // Creating an array to store up to 100 accounts
  Account accounts[100];
  int accountCount = 0;
  string hasAccount = "";
  string toLowerCaseHasAccount = "";
  int enteredAccountNumber = 0;
  bool foundAccount = false;
  int currentAccountIndex = -1;
  int choice;
  bool keepRunning = true;

  srand(time(0));

  cout << "BankGo" << endl;
  cout << "------" << endl;
  cout << endl;

  // Prompt user to log in or create a new account 
  cout << "Do you have an account? (Yes/No) :" << endl;
  cin >> hasAccount;

  // Looping through users answer to convert to lowercase
  for (int i = 0; i < hasAccount.length(); i++) {
    toLowerCaseHasAccount += tolower(hasAccount[i]);
  }

  if (toLowerCaseHasAccount == "yes") {
    cout << "Please enter your account number: " << endl;
    cin >> enteredAccountNumber;

    for (int i = 0; i < accountCount; i++){
        if (enteredAccountNumber == accounts[i].accountNumber){
            currentAccountIndex = i;
            foundAccount = true;
            break;
        }
    }
    if (!foundAccount){
        cout << "The account number you entered didn't match up with any of our accounts. Please try again!" << endl;
    }
  }

  // Create new account and generate unique 6-digit account number
  else if (toLowerCaseHasAccount == "no"){
    cin.ignore();

    cout << "Enter account holder name: " << endl;
    getline(cin, accounts[accountCount].holderName);

    accounts[accountCount].balance = 0.0;
    accounts[accountCount].transactionCount = 0;

    int generatedAccountNumber = rand() % 900000 + 100000;
    bool duplicateAccountNumber = true;

    while(duplicateAccountNumber){
        duplicateAccountNumber = false;

        for (int i = 0; i < accountCount; i++){
            if (accounts[i].accountNumber == generatedAccountNumber){
                duplicateAccountNumber = true;
                generatedAccountNumber = rand() % 900000 + 100000;
                break;
            }
        }
    }
    accounts[accountCount].accountNumber = generatedAccountNumber;

    currentAccountIndex = accountCount;
    foundAccount = true;

    cout << "Account created successfully!" << endl;
    cout << "Your account number is: " << accounts[currentAccountIndex].accountNumber << endl;
    accountCount++;
  }
  else {
    cout << "Invalid response. Please enter Yes or No." << endl;
  }
  
  // Main banking menu loop
  if (foundAccount) {
    while (keepRunning) {
      displayMenu();
      cin >> choice;

      switch (choice) {
      // Deposit funds into current account
      case 1: {
        double depositAmount;

        cout << "How much would you like to deposit: " << endl;
        cin >> depositAmount;

        if (depositAmount > 0) {
          accounts[currentAccountIndex].balance += depositAmount;

          int historyIndex = accounts[currentAccountIndex].transactionCount;

          accounts[currentAccountIndex].transactionHistory[historyIndex] = depositAmount;
          accounts[currentAccountIndex].transactionCount++;

          cout << "Deposit successful!" << endl;
          cout << "New balance: $" << accounts[currentAccountIndex].balance << endl;
        } else {
          cout << "Invalid deposit amount." << endl;
        }
        break;
      }

      // Withdraw funds from current account
      case 2: {
        double withdrawAmount;

        cout << "How much would you like to withdraw: " << endl;
        cin >> withdrawAmount;

        int historyIndex = accounts[currentAccountIndex].transactionCount;

        if (withdrawAmount > 0) {
          if (withdrawAmount <= accounts[currentAccountIndex].balance) {
            accounts[currentAccountIndex].balance -= withdrawAmount;
            accounts[currentAccountIndex].transactionHistory[historyIndex] = -withdrawAmount;
            accounts[currentAccountIndex].transactionCount++;

            cout << "Withdraw successful!" << endl;
            cout << "New balance: $" << accounts[currentAccountIndex].balance << endl;
          } else {
            cout << "Insufficient funds." << endl;
          }
        } else {
          cout << "Invalid withdrawal amount." << endl;
        }
        break;
      }

      // Get current account balance
      case 3: {
        cout << "Account balance: $" << fixed << setprecision(2) << accounts[currentAccountIndex].balance << endl;
        break;
      }

      // Transfer funds to another account
      case 4: {
        int transferAccountNumber;
        int transferAccountIndex = -1;
        bool foundTransferAccount = false;
        double transferAmount;

        cout << "Account number you want to transfer to: ";
        cin >> transferAccountNumber;

        if (transferAccountNumber == accounts[currentAccountIndex].accountNumber) {
          cout << "You cannot transfer to the same account you are logged in with." << endl;
        } else {
          for (int i = 0; i < accountCount; i++) {
            if (accounts[i].accountNumber == transferAccountNumber) {
              transferAccountIndex = i;
              foundTransferAccount = true;
              break;
            }
          }

          if (foundTransferAccount) {
            cout << "How much would you like to transfer? Your current account balance is $" << accounts[currentAccountIndex].balance << "." << endl;
            cin >> transferAmount;

            if (transferAmount > accounts[currentAccountIndex].balance || transferAmount <= 0) {
              cout << "Couldn't complete the transfer." << endl;
            } else {
              accounts[currentAccountIndex].balance -= transferAmount;
              accounts[transferAccountIndex].balance += transferAmount;

              int senderHistoryIndex = accounts[currentAccountIndex].transactionCount;
              accounts[currentAccountIndex].transactionHistory[senderHistoryIndex] = -transferAmount;
              accounts[currentAccountIndex].transactionCount++;

              int receiverHistoryIndex = accounts[transferAccountIndex].transactionCount;
              accounts[transferAccountIndex].transactionHistory[receiverHistoryIndex] = transferAmount;
              accounts[transferAccountIndex].transactionCount++;

              cout << "Transfer successful!" << endl;
              cout << "New balance: $" << accounts[currentAccountIndex].balance << endl;
            }
          } else {
            cout << "The account number did not match any of our accounts. Try again!" << endl;
          }
        }

        break;
      }

      // Get transaction history
      case 5: {
        if (accounts[currentAccountIndex].transactionCount == 0) {
          cout << "No transaction history" << endl;
        } else {
          cout << "Transaction history: " << endl;

          for (int i = 0; i < accounts[currentAccountIndex].transactionCount; i++) {
            cout << accounts[currentAccountIndex].transactionHistory[i] << endl;
          }
        }
        break;
      }

      // Generate account statement with transaction history and balance
      case 6: {
        cout << "========== Account Statement ==========" << endl;
        cout << "   Account Holder: " << accounts[currentAccountIndex].holderName << endl;
        cout << "   Account Number: " << accounts[currentAccountIndex].accountNumber << endl;
        cout << "   Current Balance: $" << fixed << setprecision(2) << accounts[currentAccountIndex].balance << endl;

        cout << "\nTransaction History:" << endl;

        if (accounts[currentAccountIndex].transactionCount == 0) {
          cout << "No transactions available." << endl;
        } else {
          for (int i = 0; i < accounts[currentAccountIndex].transactionCount; i++) {
            cout << accounts[currentAccountIndex].transactionHistory[i] << endl;
          }
        }

        cout << "=======================================" << endl;

        break;
      }

      // Exit main menu
      case 7: {
        cout << "Thank you for using BankGo. Goodbye!" << endl;
        keepRunning = false;
        break;
      }

      // Catches edge cases incase user entered a number not 1-7
      default: {
        cout << "Invalid menu choice. Please select 1-7." << endl;
        break;
      }
      }
    }
  }
}

void displayMenu() {
  cout << "1. Deposit\n";
  cout << "2. Withdraw\n";
  cout << "3. Account balance\n";
  cout << "4. Transfer\n";
  cout << "5. Transaction history\n";
  cout << "6. Account statements\n";
  cout << "7. Exit\n";
}