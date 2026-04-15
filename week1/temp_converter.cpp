#include <iostream>
#include <cctype>
using namespace std;


int main(){
    double temperature;
    char unit;

    cout << "Temperature Converter" << endl;

    cout << "Enter temperature value: " << endl;
    cin >> temperature;

    cout << "Enter Unit (C for Celsius, F for Fahrenheit)" << endl;
    cin >> unit;

    unit = tolower(unit);

    if (unit == 'c'){
        cout << temperature << "°C is equal to " << (temperature * 9.0/5 + 32) << "°F" << endl;
    } else if (unit == 'f'){
        cout << temperature << "°F is equal to " << ((temperature - 32) * 5.0/9) << "°C" << endl;
    } else {
        cout << "Invalid Unit" << endl;
    }

    return 0;
}