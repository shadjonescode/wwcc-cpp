# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <cctype>
using namespace std;

string format(int num);
string format(double num);
string format(double num, int precision);
string format(string text);
string format(string text, bool makeUpper);

int main(){
    int num1 = 1234567;
    double num2 = 45.6789;
    string s1 = "hello world of c++ programming";

    cout << "Integer formatting:\n";
    cout << "Original: " << num1 << endl;
    cout << "Formatted: " << format(num1) << endl;

    cout << "\nDouble formatting:\n";
    cout << "Original: " << num2 << endl;
    cout << "Formatted :" << format(num2) << endl;

    cout << "\nDouble formatting (with custom decimal places):\n";
    cout << "Original: " << num2 << " with precision 3\n";
    cout << "Formatted: " << format(num2, 3) << endl;

    cout << "\nString formatting:\n";
    cout << "Original: " << s1 << endl;
    cout << "Formatted: " << format(s1) << endl;

    cout << "\nUppercase or lowercase:\n";
    cout << "True: " << format(s1, true) << endl;
    cout << "False: " << format(s1, false) << endl;

    return 0;
}

string format(int num){
    string numStr = to_string(num);
    string result = "";

    for (int i = 0; i < numStr.length(); i++){
        result += numStr[i];

        int remaining = numStr.length() - i - 1;

        if (remaining % 3 == 0 && remaining != 0){
            result += ",";
        }
    }
    return result;
}

string format(double num){
    stringstream ss;
    ss << fixed << setprecision(2) << num;
    return ss.str();
}

string format(double num, int precision){
    stringstream ss;
    ss << fixed << setprecision(precision) << num;
    return ss.str();
}

string format(string text){
    for (int i = 0; i < text.length(); i++){
        if (i == 0){
            text[i] = toupper(text[i]);
        } else if(text[i-1] == ' '){
            text[i] = toupper(text[i]);
        }
    }
    return text;
}

string format(string text, bool makeUpper){
    for (int i = 0; i < text.length(); i++){
        if (makeUpper){
            text[i] = toupper(text[i]);
        } else{
            text[i] = tolower(text[i]);
        }
    }
    return text;
}