#include <iostream>
#include <string>
using namespace std;


int main(){
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello, " << name << "! Welcome to C++!" << endl;

    string movie;
    cout << "Please enter your favorite movie: ";
    getline(cin, movie);
    cout << name << "! " << movie << " is a great movie!"<< endl;
    return 0;
}

