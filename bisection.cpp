// Solution to bisection method for a non-linear equation

#include <iostream>
#include <cmath>
#include <vector>
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

void bisection_method(int degree, vector<int> coefficients, double TOLERANCE, double a, double b) {
    // First test condition:
    if (compute_function(coefficients, degree, a) * compute_function(coefficients, degree, b) > 0) {
        // Terminate with an error message.
    }

    // Repeat the process until you cross an error tolerance.
    double c;
    int iteration = 0;
    do {
        ++iteration;
        c = (a+b) / (double)2;

        if (compute_function(coefficients, degree, c) * compute_function(coefficients, degree, a) > 0) {
            a = c;
        }else {
            b = c;
        }

        cout << "Iteration " << iteration << " A: "<< a << " B: " << b << " Value: " << compute_function(coefficients, degree, c) << endl;
    }while(((b-a)/2) > TOLERANCE);
}

int main() {
    int degree = 3;
    vector<int> coeffs = ask_coefficients(degree);

    // Testing the vector
    for(int i=coeffs.size()-1; i>=0; i--) {
        cout << "A^" << i << " :" << coeffs[i] << endl;
    }
    
    // Testing the compute function
    cout << "Value: " << compute_function(coeffs, degree, 1) << endl;
    cout << "Value: " << compute_function(coeffs, degree, 2) << endl;

    // Testing the bisection function
    bisection_method(degree, coeffs, 0.00001, -5, 5);
    return 0;
}