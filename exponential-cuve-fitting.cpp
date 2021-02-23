// Least Squares Method for Exponential curve fitting.
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int N, m = 0;
    cout << "Enter the number of data:" << endl;
    cin >> N;

    vector<double> x_values(N);
    vector<double> y_values(N);

    for(int i=0; i<N; i++) {
        cout << "Enter x" << i+1 << " and y" << i+1 << endl;
        cin >> x_values[i] >> y_values[i]; 
    }
    char C;
    cout << "Enter a for y=a*x^b form and any other key for y=a*e^(bx)" << endl;
    cin >> C;
    if (C == 'a') {
        m = 1;
    }

    double sum_X = 0, sum_X2 = 0, sum_Y = 0, sum_XY = 0;

    if (m == 1) {
        for(int i=0; i<N; i++) {
            sum_X += log(x_values[i]);
            sum_X2 += log(x_values[i]) * log(x_values[i]);
            sum_Y += log(y_values[i]);
            sum_XY += log(x_values[i]) * log(y_values[i]);
        }
    } else {
        for(int i=0; i<N; i++) {
            sum_X += x_values[i];
            sum_Y += log(y_values[i]);
            sum_X2 += x_values[i] * x_values[i];
            sum_XY += x_values[i] * log(y_values[i]);
        }
    }

    double B = (N * sum_XY - sum_X* sum_Y)/(double)(N * sum_X2 - sum_X * sum_X);
    double A = (sum_Y* sum_X2 - sum_XY * sum_X)/(double)(N * sum_X2 - sum_X * sum_X);

    double a = exp(A);

    if (m) {
        cout << "The equation is: y=" << a << "*x^" << B;
    }
    else {
        cout << "The equation is: y=" << a << "*e^(" << B << ")x";
    }

    return 0;
}