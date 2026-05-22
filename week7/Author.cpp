#include "Author.h"
#include <iostream>
using namespace std;

Author::Author(string n, int year){
    name = n;
    birthYear = year;
}

string Author::getName() const{
    return name;
}

int Author::getBirthYear() const{
    return birthYear;
}

void Author::display() const{
    cout << "Author: " << name << "(born " << birthYear << ")" << endl;
}