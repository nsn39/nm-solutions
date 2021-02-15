// Gauss Jordan Method to solve a system of linear equations
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Asking  coefficients from the user..
vector<vector<double>>ask_coefficients(int no_of_unknowns) {
    vector<vector<double>> coeffs;

    for(int i=0; i<no_of_unknowns; i++) {
        vector<double> temp(no_of_unknowns+1, 0);

        for(int j=0; j<no_of_unknowns+1; j++) {
            cout << "Enter " << i << "," << j << endl;
            cin >> temp[j];  
        }
        coeffs.push_back(temp);
    }
    
    return coeffs;
}

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
    int no_of_unknowns = 3;

    // Testing the ask_coefficients function:
    vector<vector<double>> coeffs = ask_coefficients(no_of_unknowns);
    cout << coeffs[1][1] << endl;

    // Testing the gauss jordan method
    gauss_jordan(no_of_unknowns, coeffs);
    return 0;
}