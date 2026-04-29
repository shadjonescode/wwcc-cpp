#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

static int conversion_counter = 0;

double dollartoEuro(double amount) {
    return amount * 0.85;
}

double dollartoPound(double amount) {
    return amount * 0.74;
}

double dollartoYen(double amount) {
    return amount * 110.33;
}

int main() {
    char yes_or_no = 'y';

    while (yes_or_no == 'y') {
        int choice;
        double amount;

        cout << "CURRENCY CONVERTER" << endl;
        cout << "------------------" << endl;

        cout << "1. Convert USD to Euro (EUR)" << endl;
        cout << "2. Convert USD to British Pound (GBP)" << endl;
        cout << "3. Convert USD to Japanese Yen (JPY)" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice (1-4): " << endl;
        cin >> choice;

        if (choice == 4) {
            break;
        }

        if (choice < 1) {
            cout << "Invalid choice!" << endl;
            continue;
        }
        else if (choice > 4){
            cout << "Invalid choice!" << endl;
            continue;
        }
        cout << "Enter amount in USD: " << endl;
        cin >> amount;

        if (choice == 1) {
            double result = dollartoEuro(amount);
            cout << amount << " USD = " << fixed << setprecision(2) << result << " EUR" << endl;
            conversion_counter++;
        } 
        else if (choice == 2) {
            double result = dollartoPound(amount);
            cout << amount << " USD = " << fixed << setprecision(2) << result << " GBP" << endl;
            conversion_counter++;
        } 
        else if (choice == 3) {
            double result = dollartoYen(amount);
            cout << amount << " USD = " << fixed << setprecision(2) << result << " JPY" << endl;
            conversion_counter++;
        }

        cout << "Number of conversions performed: " << conversion_counter << endl;

        cout << "Would you like to perform another conversion? (y/n): " << endl;
        cin >> yes_or_no;
        yes_or_no = tolower(yes_or_no);
    }

    cout << "Thank you for using the Currency Converter! You used it " << conversion_counter << " times!" << endl;

    return 0;
}