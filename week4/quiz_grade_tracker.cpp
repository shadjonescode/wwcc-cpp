#include <iostream>
#include <iomanip>
using namespace std;



int main(){
    const int num_quizzes = 5;
    int score[num_quizzes];

    int sum = 0;
    int high_quiz = 1;
    int low_quiz = 1;
    int filled_blocks = 0;
    int empty_blocks = 0;
    int grade_a_amount = 0;
    int grade_b_amount = 0;
    int grade_c_amount = 0;
    int grade_d_amount = 0;
    int grade_f_amount = 0;

    cout << "QUIZ GRADE TRACKER" << endl;
    cout << "------------------" << endl;



    for (int i = 0; i < num_quizzes; i++){
        cout << "Enter Score for Quiz " << i + 1 << " (0-100): ";
        cin >> score[i];
    }

    int max_score = score[0];
    int low_score = score[0];

    cout << "Quiz Results:" << endl;
    
    for (int i = 0; i < num_quizzes; i++){
        sum += score [i];
        if (score[i] >= 90){
            cout << "Quiz " << i + 1 << ": " << score[i] << " (A)" << endl;
            grade_a_amount++;
        }
        else if (score[i] >= 80){
            cout << "Quiz " << i + 1 << ": " << score[i] << " (B)" << endl;
            grade_b_amount++;
        }
        else if (score[i] >= 70){
            cout << "Quiz " << i + 1 << ": " << score[i] << " (C)" << endl;
            grade_c_amount++;
        }
        else if (score[i] >= 60){
            cout << "Quiz " << i + 1 << ": " << score[i] << " (D)" << endl;
            grade_d_amount++;
        }
        else{
            cout << "Quiz " << i + 1 << ": " << score[i] << " (F)" << endl;
            grade_f_amount++;
        }
        if (score[i] > max_score){
            max_score = score[i];
            high_quiz = i + 1;
        }

        if (score[i] < low_score){
            low_score = score[i];
            low_quiz = i + 1;
        }
    }

    cout << "Score Chart: |1||2||3||4||5||6||7||8||9||10|" << endl;
    for (int i = 0; i < num_quizzes; i++){

        filled_blocks = score[i] / 10;
        empty_blocks = 10 - filled_blocks;

        cout << "Quiz " << i + 1 << " (" << score[i] << "): "; 

        for (int block = 0; block < filled_blocks; block++){
            cout << "|█|";
        }
    

        for (int block = 0; block < empty_blocks; block++){
            cout << "|░|";
        }
        cout << endl;
    }

    double avg_grade = static_cast<double>(sum) / num_quizzes;



    cout << "Statistics:" << endl;
    cout << "   Average score: " << fixed << setprecision(1) << avg_grade << endl;
    cout << "   Highest score: " << max_score << " (Quiz " << high_quiz << ")" << endl;
    cout << "   Lowest score: " << low_score << " (Quiz " << low_quiz << ")" << endl;
    if (avg_grade >= 90){
        cout << "   Overall grade: A" << endl;
    }
    else if (avg_grade >= 80){
        cout << "   Overall grade: B" << endl;
    }
    else if (avg_grade >= 70){
        cout << "   Overall grade: C" << endl;
    }
    else if (avg_grade >= 60){
        cout << "   Overall grade: D" << endl;
    }
    else{
        cout << "   Overall grade: F" << endl;
    }
    cout << "Grade Distribution:" << endl;
    cout << "   A: " << grade_a_amount << endl;
    cout << "   B: " << grade_b_amount << endl;
    cout << "   C: " << grade_c_amount << endl;
    cout << "   D: " << grade_d_amount << endl;
    cout << "   F: " << grade_f_amount << endl;

    return 0;
}