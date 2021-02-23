// Least Squares Method of Curve Fitting Polynomial form
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void gauss_jordan(int no_of_unknowns, vector<vector<double>> coeffs) {

    // Looping through to convert the matrix into reduced-row echelon form.
    for(int i=0; i<no_of_unknowns; i++) {
        if (coeffs[i][i] == 0) {
            cout << "Error: Pivot element zero." << endl;
            return;
        }

        for(int j=0; j<no_of_unknowns; j++) {
            if (i != j) {
                double ratio = coeffs[j][i]/(double)coeffs[i][i];

                for(int k=0; k<no_of_unknowns+1; k++) {
                    coeffs[j][k] -= ratio * coeffs[i][k];
                }
            }
        }
    }

    // Displaying the output values:
    for(int i=0; i<no_of_unknowns; i++) {
        cout << "x" << i+1 << " : " << coeffs[i][no_of_unknowns]/(double)coeffs[i][i] << endl;
    }
}

int main() {
    int N, D;
    cout << "Enter the no of entries and degree of the polynomial:" << endl;
    cin >> N >> D;

    if (N < D) {
        cout << "Error." << endl;
        return 0;
    }   

    vector<double> x_values(N);
    vector<double> y_values(N);

    for(int i=0; i<N; i++) {
        cout << "Enter x" << i+1 << " and y" << i+1 << endl;
        cin >> x_values[i] >> y_values[i];
    }

    double P = 0;

    vector<vector<double>> M(D+1, vector<double>(D+2,0));

    // Obtaining the summation values in the form of a matrix.
    for(int i=0; i<D+1; i++) {
        for(int j=0; j<D+1; j++) {
            for(int k=0; k<N; k++) {
                M[i][j] += pow(x_values[k], P+j);
                if (j == 0) {
                    M[i][D+1] += pow(x_values[k], P) * y_values[k];
                }
            }
        }
        P += 1;
    }

    // Printing the matrix first
    for(int i=0; i<D+1; i++) {
        for(int j=0; j<=D+1; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    // Using Gauss Jordan Method to find the values of unknowns.
    gauss_jordan(D+1, M);

    return 0;
}