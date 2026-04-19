# include <iostream>
# include <cstdlib>
# include <ctime>
# include <iomanip>
using namespace std;

int main(){
    
    srand(time(0));

    int flips;
    int heads = 0;
    int tails = 0;

    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate" << endl;
    cin >> flips;

    for (int i = 0; i < flips; i++){
        if (rand() % 2 == 0) {
            heads++;
        } else{
            tails++;
        }
    }

    double headsPercent = (double)heads / flips * 100;
    double tailsPercent = (double)tails / flips * 100;

    cout << fixed << setprecision(2);
    cout << "Simulating " << flips << " coin flips..." << endl;
    cout << "\nResults:\n";
    cout << "Heads: " << heads << " (" << headsPercent << "%)" << endl;
    cout << "Tails: " << tails << " (" << tailsPercent << "%)" << endl;
    
    return 0;
}