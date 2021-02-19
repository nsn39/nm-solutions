// Gauss elimination method to solve system of linear equations of n unknowns.
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Asking  coefficients from the user..
vector<vector<double>>ask_coefficients(int N) {
    vector<vector<double>> coeffs;

    for(int i=0; i<N; i++) {
        vector<double> temp(N+1, 0);

        for(int j=0; j<N+1; j++) {
            cout << "Enter " << i << "," << j << endl;
            cin >> temp[j];  
        }
        coeffs.push_back(temp);
    }
    
    return coeffs;
}

// Applying gauss-elimination
void gauss_elimination(vector<vector<double>> coeffs, int N) {
    cout << "Gauss Elimination" << endl;

    for(int i=0; i<N-1; i++) {
        if (coeffs[i][i] == 0) {
            cout << "Mathematical error." << endl;
            return;
        }

        for(int j=i+1; j<N; j++) {
            double ratio = coeffs[j][i]/(double)coeffs[i][i];

            for(int k=0; k<N+1; k++) {
                coeffs[j][k] -= ratio * coeffs[i][k];
            }
        }
    }

    vector<double> final_values(N);
    // Using back-substitution to obtain solution.
    final_values[N-1] = coeffs[N-1][N]/(double)coeffs[N-1][N-1];

    for(int i=N-2; i>=0; i--) {
        final_values[i] =   coeffs[i][N];

        for(int j=i+1; j<N; j++) {
            final_values[i] -= coeffs[i][j] * final_values[j];
        }

        final_values[i] /= (double)coeffs[i][i];
    }

    // Displaying the final values
    for(int i=0; i<N; i++) {
        cout << "x" << i+1 << ": " << final_values[i] << endl;
    }
}

int main() {

    // Ask the no of unknowns.
    int N;
    cout << "Enter the no of variables. " << endl;
    cin >> N;

    // Asking the coefficients from the user.
    vector<vector<double>> coeffs = ask_coefficients(N);

    // Testing the gauss-elimination function
    gauss_elimination(coeffs, N);

    return 0;
}