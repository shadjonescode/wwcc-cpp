#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cctype>

using namespace std;

struct Question {
    string category;
    int difficulty;
    string questionText;
    string answer;
};

enum class GameState {
    INTRO,
    ROUND1,
    ROUND2,
    ROUND3,
    ROUND4,
    ROUND5,
    WIN,
    LOSE
};

string toLowerCase(string text) {
    for (char& c : text) {
        c = tolower(c);
    }

    return text;
}

vector<Question> loadQuestions(const string& filename) {
    vector<Question> questions;
    ifstream file(filename);

    if (!file) {
        cout << "Error: could not open " << filename << endl;
        return questions;
    }

    string line;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string category, difficultyText, questionText, answer;

        getline(ss, category, '|');
        getline(ss, difficultyText, '|');
        getline(ss, questionText, '|');
        getline(ss, answer, '|');

        Question q;
        q.category = category;
        q.difficulty = stoi(difficultyText);
        q.questionText = questionText;
        q.answer = answer;

        questions.push_back(q);
    }

    return questions;
}

Question getQuestion(const vector<Question>& questions, const string& category, int difficulty) {
    vector<Question> matches;

    for (const auto& q : questions) {
        if (q.category == category && q.difficulty == difficulty) {
            matches.push_back(q);
        }
    }

    if (matches.empty()) {
        return {"None", 0, "No question found.", "None"};
    }

    return matches[rand() % matches.size()];
}

void displayCategories(const vector<string>& categories) {
    for (int i = 0; i < categories.size(); i++) {
        cout << i + 1 << ". " << categories[i] << endl;
    }
}

string chooseCategory(vector<string>& categories) {
    int choice;

    displayCategories(categories);
    cout << "Choose a category by number: ";

    while (!(cin >> choice) || choice < 1 || choice > categories.size()) {
        cout << "Invalid choice. Enter a number from 1 to " << categories.size() << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string selectedCategory = categories[choice - 1];
    categories.erase(categories.begin() + choice - 1);

    return selectedCategory;
}

bool askQuestion(const Question& q) {
    string userAnswer;

    cout << endl;
    cout << q.questionText << endl;
    cout << "Answer: ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, userAnswer);

    string playerAnswer = toLowerCase(userAnswer);
    string correctAnswer = toLowerCase(q.answer);

    if (playerAnswer == correctAnswer) {
        cout << "Correct!" << endl;
        return true;
    }
    else {
        cout << "Incorrect." << endl;
        cout << "Correct answer: " << q.answer << endl;
        return false;
    }
}

void saveResults(const string& playerName, int score) {
    ofstream resultsFile("results.txt");

    resultsFile << "Player: " << playerName << endl;
    resultsFile << "Score: " << score << "/25" << endl;

    resultsFile.close();
}

int main() {
    srand(time(0));

    vector<Question> questions = loadQuestions("questions.txt");

    if (questions.empty()) {
        cout << "No questions were loaded. Check your questions.txt file." << endl;
        return 1;
    }

    string playerName;
    int score = 0;

    cout << "Welcome to Knowledge Quest!" << endl;
    cout << "Enter your name: ";
    getline(cin, playerName);

    cout << endl;
    cout << "The audience cheers as you step onto the stage." << endl;
    cout << "A spotlight shines down on you." << endl;
    cout << "\"Welcome to Knowledge Quest, " << playerName << "!\" the host announces." << endl;
    cout << "\"You must survive five rounds of trivia to win the grand prize.\"" << endl;
    cout << "\"Choose wisely and good luck!\"" << endl;

    for (int difficulty = 1; difficulty <= 5; difficulty++) {
        vector<string> categories = {"Sports", "Gaming", "History", "Technology", "Music"};

        cout << "\n==========================" << endl;
        cout << "Round " << difficulty << " - Difficulty " << difficulty << endl;
        cout << "==========================" << endl;
        switch (difficulty) {
            case 1:
                cout << "The warm-up round begins!" << endl;
                break;
            case 2:
                cout << "The questions are getting tougher." << endl;
                break;
            case 3:
                cout << "You have reached the halfway point!" << endl;
                break;
            case 4:
                cout << "Only the best contestants make it this far." << endl;
                break;
            case 5:
                cout << "Welcome to the championship round!" << endl;
                break;
        }

        for (int i = 0; i < 5; i++) {
            cout << "\nQuestion " << i + 1 << " of 5" << endl;

            string chosenCategory = chooseCategory(categories);
            Question q = getQuestion(questions, chosenCategory, difficulty);

            if (askQuestion(q)) {
                score++;
            }

            cout << "Current Score: " << score << endl;
        }
    }

    cout << "\n==========================" << endl;
    cout << "The final buzzer sounds and the audience waits in suspense." << endl;
    cout << "The host opens the final envelope..." << endl;
    cout << "Game Over!" << endl;
    cout << "Final Score: " << score << "/25" << endl;

    if (score >= 18) {
        cout << "Congratulations " << playerName << "! You won the grand prize!" << endl;
    }
    else {
        cout << "Sorry " << playerName << ", better luck next time!" << endl;
    }

    cout << "==========================" << endl;

    saveResults(playerName, score);

    return 0;
}