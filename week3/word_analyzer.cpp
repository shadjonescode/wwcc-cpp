#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;



int main(){
    char yes_or_no = 'y';
    while (yes_or_no == 'y'){
        string word;
        char first_letter;
        string reversed_word = "";
        string lower_reversed = "";
        bool palindrome_yes_or_no;

        cout << "Enter a word: " << endl;
        cin >> word;

        string lower_word = word;

        for (int i = 0; i < lower_word.length(); i++){
            lower_word[i] = tolower(lower_word[i]);
        }

        int vowels = 0;
        int consonants = 0;

        for (int i = 0; i < word.length(); i++){
            char letter = tolower(word[i]);
            if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u'){
            vowels++;
        }
        else if (isalpha(letter)){
            consonants++;
        }
    }



        first_letter = toupper(word[0]);

        for (int i = word.length() - 1; i >= 0; i--){
            reversed_word += word[i];
        }

        lower_reversed = reversed_word;

        for (int i = 0; i < lower_reversed.length(); i++){
            lower_reversed[i] = tolower(lower_reversed[i]);
        }

        if (lower_word == lower_reversed){
            palindrome_yes_or_no = true;
        }
        else {
            palindrome_yes_or_no = false;
        }


        cout << "Word Analysis:" << endl;
        cout << "--------------" << endl;

        cout << "Number of vowels: " << vowels << endl;
        cout << "Number of consonants: " << consonants << endl;
        cout << "First letter: " << first_letter << endl;
        cout << "Reversed: " << reversed_word << endl;
        
        if (palindrome_yes_or_no){
            cout << "Is palindrome: Yes" << endl;
        }
        else{
            cout << "Is palindrome: No" << endl;
        }

        cout << "Would you like to analyze another word? (y/n)" << endl;
        cin >> yes_or_no;
        yes_or_no = tolower(yes_or_no);

        while (yes_or_no != 'y' && yes_or_no != 'n'){
            cout << "Invalid choice. Try again!" << endl;
            cin >> yes_or_no;
            yes_or_no = tolower(yes_or_no);
        }
        
        if (yes_or_no == 'n'){
            break;
        }
    }
    return 0;
}