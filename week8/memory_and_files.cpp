#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void swapByReference(int& a, int& b);
int findMax(int* arr, int size);

void writeNote(ofstream& file, const string& note);
void displayNotes(ifstream& file);

int main(){
    cout << "=== PART 1: MEMORY AND ADDRESSING ===" << endl;

    int age = 25;
    double gpa = 3.75;
    char grade = 'A';

    cout << "\nVariable value and addresses:" << endl;
    cout << "int age = " << age << " at address " << &age << endl;
    cout << "double gpa = " << gpa << " at address " << &gpa << endl;
    cout << "char grade = " << grade << " at address " << static_cast<void*>(&grade) << endl;

    cout << "\nReference demonstration:" << endl;

    int& refAge = age;

    cout << "Before: age = " << age << endl;

    refAge = 26;

    cout << "After modifying through reference: age = " << age << endl;

    cout << "Address of age: " << &age << endl;
    cout << "Address of refAge: " << &refAge << endl;

    cout << "\nPointer demonstration:" << endl;

    int* ptrAge = &age;

    cout << "Pointer stores address: " << ptrAge << endl;
    cout << "Value at address: " << *ptrAge << endl;

    *ptrAge = 30;

    cout << "After modifying through pointer:" << endl;
    cout << "age = " << age << endl;

    cout << "\nNull pointer check:" << endl;

    int* nullPtr = nullptr;
    if (nullPtr != nullptr){
        cout << *nullPtr << endl;
    } else {
        cout << "Pointer is null. Cannot dereference." << endl;
    }

    cout << "\nSwap by reference:" << endl;

    int num1 = 10;
    int num2 = 20;

    cout << "Before swap: " << num1 << " " << num2 << endl;

    swapByReference(num1, num2);

    cout << "After swap: " << num1 << " " << num2 << endl;


    cout << "\nFinding maximum value:" << endl;

    int numbers[] = {12, 45, 8, 67, 23};

    int largest = findMax(numbers, 5);

    cout << "Largest value: " << largest << endl;

    cout << "\nArray-pointer relationship:" << endl;

    cout << "numbers[0] = " << numbers[0] << " and *(numbers + 0) = " << *(numbers + 0) << endl;

    cout << "numbers[1] = " << numbers[1] << " and *(numbers + 1) = " << *(numbers + 1) << endl;

    cout << "\n=== PART 2: FILE I/O ===" << endl;

    ofstream outFile("notes.txt", ios::app);

    if (!outFile){
        cerr << "Error opening notes.txt for writing." << endl;
        return 1;
    }

    string note;

    for (int i = 1; i <= 3; i++){
        cout << "Enter note " << i << ": ";
        getline(cin, note);

        writeNote(outFile, note);
    }

    outFile.close();

    cout << "\nNotes written to notes.txt successfully." << endl;

    ifstream inFile("notes.txt");

    if (!inFile){
        cerr << "Error opening notes.txt for reading." << endl;
        return 1;
    }

    cout << "\nReading notes back from file:" << endl;

    displayNotes(inFile);

    inFile.close();

    return 0;
}

void swapByReference(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int findMax(int* arr, int size){
    int max = *arr;
        
    for (int i = 1; i < size; i++){
        if (*(arr + i) > max){
            max = *(arr + i);
        }
    }
    return max;
}

void writeNote(ofstream& file, const string& note){
    file << note << endl;
}

void displayNotes(ifstream& file){
    string line;

    while (getline(file, line)){
        cout << line << endl;
    }
}