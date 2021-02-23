// Lagrange Interpolation.
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N;
    cout << "Enter the no of variables." << endl;
    cin >> N;

    vector<double> x_values(N);
    vector<double> y_values(N);

    for(int i=0; i<N; i++) {
        cout << "Enter x" << i+1 << endl;
        cin >> x_values[i];
        cout << "Enter y" << i+1 << endl;
        cin >> y_values[i];
    }

    double arX, arY = 0;
    cout << "Enter the value of xp :" << endl;
    cin >> arX;

    for(int i=0; i<N; i++) {
        double p = 1;
        for(int j=0; j<N; j++) {
            if (i != j) {
                p *= (arX - x_values[j])/(double)(x_values[i] - x_values[j]);
            }
        }
        arY += p * y_values[i];
    }

    cout << "Value of p :" << arY << endl;

    return 0;
}