#include <iostream>
using namespace std;

int main(){
    char op;
    double num1, num2;
    
    cout << "Please select your operator (+, -, *, /): ";
    cin >> op;


    cout << "Please enter your numbers: ";
    cin >> num1 >> num2;

    if (op == '+'){
        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    } else if (op == '-'){
        cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    } else if (op == '*'){
        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    } else if (op == '/'){
        if (num2 == 0){
            cout << "Cannot divide by 0" << endl;
        } else {
            cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
        }
    } else {
        cout << "Invalid operator!" << endl;
    }

    return 0;
}