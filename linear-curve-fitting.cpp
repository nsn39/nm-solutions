// Least Squares Meethod of Curve Fitting For Linear Forms.
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main() {
    int N;
    cout << "Enter no of data:" << endl;
    cin >> N;

    vector<double> x_val(N);
    vector<double> y_val(N);

    for(int i=0; i<N; i++) {
        cout << "Enter x" << i+1 << endl;
        cin >> x_val[i];

        cout << "Enter y" << i+1 << endl;
        cin >> y_val[i];
    }

    double SUM_X = 0, SUM_X2 = 0, SUM_Y = 0, SUM_XY = 0;

    // Calculating required sums.
    for(int i=0; i<N; i++) {
        SUM_X += x_val[i];
        SUM_X2 += x_val[i] * x_val[i];
        SUM_Y += y_val[i];
        SUM_XY += x_val[i] * y_val[i];
    }

    // Calculating required values of 'a' and 'b':
    double b = (N * SUM_XY - SUM_X * SUM_Y) / (double)(N * SUM_X2 - SUM_X * SUM_X);
    double a = (SUM_Y - b * SUM_X)/(double)N;

    cout << "The linear equation is : y=" << a << "+" << b << "x" << endl;

    return 0;
}