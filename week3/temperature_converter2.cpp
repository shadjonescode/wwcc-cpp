#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

void convertTemperature(double temp, char unit, string &warning){
    warning = "";
    if (unit == 'C'){
        if (temp < -273.15){
            warning = "Warning: Temperature below absolute zero (-273.15°C)!";
        } 
    }
    else if (unit == 'F'){
        if (temp < -459.67){
            warning = "Warning: Temperature below absolute zero (-459.67°F)!";
            }
    }
    else if (unit == 'K'){
        if (temp < 0){
            warning = "Warning: Temperature below absolute zero (0K)!";
            }
    }
    if (warning != ""){
        return;
    }
    
    switch(unit){
        case 'C':{
            double kelvin = temp + 273.15;
            double fahrenheit = (temp * 9/5) + 32;
            cout << "Temperature in Celsius: " << temp << endl;
            cout << "Temperature in Kelvin: " << fixed << setprecision(2) << kelvin << endl;
            cout << "Temperature in Fahrenheit: " << fixed << setprecision(2) << fahrenheit << endl;
            break;
        }

        case 'F':{
            double celsius = (temp - 32) * 5/9;
            double kelvin = celsius + 273.15;
            cout << "Temperature in Fahrenheit: " << temp << endl;
            cout << "Temperature in Kelvin: " << fixed << setprecision(2) << kelvin << endl;
            cout << "Temperature in Celsius: " << fixed << setprecision(2) << celsius << endl;
            break;
        }

        case 'K':{
            double celsius = temp - 273.15;
            double fahrenheit = (celsius * 9/5) + 32;
            cout << "Temperature in Kelvin: " << fixed << setprecision(2) << temp << endl;
            cout << "Temperature in Celsius: " << fixed << setprecision(2) << celsius << endl;
            cout << "Temperature in Fahrenheit: " << fixed << setprecision(2) <<fahrenheit << endl;
            break;
        }
        default:
            cout << "Invalid unit entered!" << endl;
    }
}

int main(){
    double temp;
    cout << "Enter a temperature value: " << endl;
    cin >> temp;

    char unit;
    cout << "Enter the unit (C for Celsius, F for Fahrenheit, K for Kelvin)" << endl;
    cin >> unit;
    unit = toupper(unit);

    string warning;
    convertTemperature(temp, unit, warning);

    if (warning != ""){
        cout << warning << endl;
    }

    return 0;
}

