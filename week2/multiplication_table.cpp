# include <iostream>
# include <iomanip>
using namespace std;

int main(){
    int start, end;

    cout << "Multiplication Table Generator" << endl << endl;

    cout << "Enter starting number: ";
    cin >> start;

    cout << "Enter ending number: ";
    cin >> end;

    if (start > end){
        cout << "Error: Starting number must be less than ending number." << endl;
        return 1;
    }
    cout << endl;

    cout << setw(4) << " " << " |";
    for (int i = start; i <= end; i++) {
        cout << setw(3) << i << " |";
    }
    cout << endl;

    cout << " ----";
    for (int i = start; i <= end; i++){
        cout << "|----";
    }
    cout << "|" << endl;

    for (int i = start; i <= end; i++){
        cout << setw(4) << i << " |";

        for (int j = start; j <= end; j++){
            cout << setw(3) << i * j << " |";
        }
        cout << endl;
    }

    return 0;
}