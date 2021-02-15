// Secant method to find the root of a non-linear equation
#include <iostream>
#include <cmath>
#include <vector>

const int MAX_ITERATIONS = 30;

using namespace std;


vector<int> ask_coefficients(int degree) {
    cout << "Asking";

    vector<int> coefficients(degree+1);
    // Taking in the coefficients from the input stream
    for(int i=degree; i>=0; i--) {
        cout << "Enter the value of x^" << i << endl;
        cin >> coefficients[i];
    }

    return coefficients;
}

double compute_function(vector<int> coefficients, int degree, double value) {
    double ans = 0;

    for(int i=0; i<=degree; i++) {
        ans += pow(value, i) * coefficients[i];
    }

    return ans;
}

double secant_method(vector<int> coefficients, int degree, double x0, double x1, int ITERATIONS) {

    double ans;
    int step = 0;
    while (step < ITERATIONS) {
        double first_exp = (x1 - x0)/(double)(compute_function(coefficients, degree, x1)-compute_function(coefficients, degree, x0));

        ans = x1 - (compute_function(coefficients, degree, x1) * first_exp);

        step++;
        x0 = x1;
        x1 = ans;
        cout << "Iteration : " << step << " x" << step << " :" << x1 << " x" << step-1 << " :" << x0 << endl;
    }

    return ans;
}

int main() {
    int degree = 2;

    // Testing the secant method
    vector<int> coeffs = ask_coefficients(degree);

    double root_value = secant_method(coeffs,degree, 100, 300, MAX_ITERATIONS);

    return 0;
}