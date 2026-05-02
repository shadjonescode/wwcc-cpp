#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(){
    string my_string = "";
    int word_count = 0;
    int sentence_count = 0;
    int total_word_length = 0;
    double average_word_length;


    cout << "TEXT ANALYZER" << endl;
    cout << "-------------" << endl;

    cout << "Enter a sentence or paragraph: " << endl;
    getline(cin,my_string);

    cout << endl;
    cout << "Analysis:" << endl;
    cout << "   Characters (with spaces): " << my_string.length() << endl;

    stringstream ss(my_string);
    string word;
    string longest_word = "";

    while (ss >> word){
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        word_count++;

        if (word.length() > longest_word.length()){
            longest_word = word;
        }

        total_word_length += word.length();

    }
    if (word_count > 0){
        average_word_length = static_cast<double>(total_word_length) / word_count;
    }
    else{
        average_word_length = 0;
    }
       

    for (int i = 0; i < my_string.length(); i++){

        if (my_string[i] == '.' || my_string[i] == '!' || my_string[i] == '?'){
            sentence_count++;
        }
    }
    cout << "   Word count: " << word_count << endl;


    
    cout << "   Sentence count: " << sentence_count << endl;

    cout << "   Longest word: " << longest_word << endl;

    cout << "   Average word length: " << fixed << setprecision(1) << average_word_length << endl;

    string upper_version = my_string;
    string lower_version = my_string;

    for (int i = 0; i < upper_version.length(); i++){
        upper_version[i] = toupper((upper_version[i]));
    }

    for (int i = 0; i < lower_version.length(); i++){
        lower_version[i] = tolower((lower_version[i]));
    }

    cout << endl;
    cout << "Uppercase:" << endl;
    cout << "   " << upper_version << endl;

    cout << endl;
    cout << "Lowercase:" << endl;
    cout << "   " << lower_version << endl;



    
    return 0;
}