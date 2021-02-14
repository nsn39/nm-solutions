// Solution to Newton Rhapson Method for finding root of a non-linear equation
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

vector<int> find_derivative(vector<int> coefficients, int degree) {
    cout << "Finding derivatives" << endl;

    vector<int> derivative(degree);
    for(int i=1; i<=degree; i++) {
        derivative[i-1] = i*coefficients[i];
    }

    return derivative;
}

double compute_function(vector<int> coefficients, int degree, double value) {
    double ans = 0;

    for(int i=0; i<=degree; i++) {
        ans += pow(value, i) * coefficients[i];
    }

    return ans;
}

double newton_rhapson(double initial_guess, double TOLERANCE, vector<int> f_of_x, vector<int> g_of_x, int degree) {
    double x0 = initial_guess, x1;
    int step = 0;

    do {
        ++step;
        double f_val = compute_function(f_of_x, degree, x0);
        double g_val = compute_function(g_of_x, degree-1, x0);

        // If g(x0) == 0 then throw an error.
        if (g_val == 0) {
            cout << "Derivative undefined for the guess";
            return 0;
        }

        x1 = x0 - (f_val/(double)g_val);
        x0 = x1;

        cout << "Iteration: " << step << " x = " << x1 << endl;

    }while(abs(compute_function(f_of_x, degree, x1)) > TOLERANCE);

    return x1;
}

int main() {
    int degree = 3;

    // Testing the derivative function
    vector<int> coeffs = ask_coefficients(degree);
    vector<int> derivative = find_derivative(coeffs, degree);

    for(int i=0; i<degree; i++) {
        cout << derivative[i] << " ";
    }

    // Testing the newton-rhapson method
    double ans = newton_rhapson(10, 0.0001, coeffs, derivative, degree);
    return 0;
}