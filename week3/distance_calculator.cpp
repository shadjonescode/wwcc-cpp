# include <iostream>
# include <cmath>
# include <iomanip>
# include <utility>
using namespace std;

double calculateDistance(double x1, double y1, double x2, double y2){
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

pair<double, double> calculateMidpoint(double x1, double y1, double x2, double y2){
    double midX = (x1 + x2) / 2;
    double midY = (y1 + y2) / 2;
    return {midX, midY};
}

int main(){
    cout << "Enter the coordinates of the first point: " << endl;
    double x1, y1;

    cout << "x1: ";
    cin >> x1;

    cout << "y1: ";
    cin >> y1;

    cout << "\nEnter the coordinates of the second point:\n";
    double x2, y2;

    cout << "x2: ";
    cin >> x2;
    
    cout << "y2: ";
    cin >> y2;

    double distance = calculateDistance(x1, y1, x2, y2);

    auto midpoint = calculateMidpoint(x1, y1, x2, y2);

    cout << fixed << setprecision(2);

    cout << "The distance between (" << x1 << ", " << y1 << ") and (" << x2 << ", "<< y2 <<") is : " << distance << endl;
    
    cout << "The midpoint of (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") is (" << midpoint.first << ", " << midpoint.second << ")." << endl;

    return 0;
}