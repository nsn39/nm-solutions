// Power method to find the dominant Eigenvalue and Eigenvector of a matrix
#include<iostream>
#include<cmath>
#include<vector>

const int TOLERANCE = 0.00001;

using namespace std;

vector<vector<double>> read_matrix(int order) {

    vector<vector<double>> one(order, vector<double>(order, 0));

    for(int i=0; i<order; i++) {
        for(int j=0; j<order; j++) {
            cout << "Enter M" << i << "," << j << endl;
            cin >> one[i][j];
        }
    }
    //cout << "RETURNING FROM READ" << endl;
    return one;
}

vector<double> read_guess_eigenvector(int order) {
    vector<double> guess(order);
    for(int i=0; i<order; i++) {
        cout << "Enter X" << i << endl;
        cin >> guess[i];
    }
    return guess;
}

vector<double> multiply(vector<vector<double>> A, vector<double> X, int order) {
    vector<double> ans(order, 0);

    for(int i=0; i<order; i++) {
        for(int j=0; j<order; j++) {
            ans[i] += A[i][j] * X[j];
        }
    }
    return ans;
}

void power_method(vector<vector<double>> matrix, vector<double> first_guess, double TOLERANCE, int order) {

    vector<double> eigenvector = first_guess;

    double LAMBDA_OLD = 1;
    double LAMBDA_NEW = 1;

    do {
        LAMBDA_OLD = LAMBDA_NEW;

        eigenvector = multiply(matrix, eigenvector, order);


        // Iterating through new_vector to get max element.
        double temp = 0;
        for(auto &x: eigenvector) {
            if (x > temp) {
                temp = x;
            }
        }
        LAMBDA_NEW = temp;

        // Normalizing the vector
        for(auto &x: eigenvector) {
            x /= (double)LAMBDA_NEW;
        }

        // Printing the eigenvalue and eigenvector to the console.
        cout << "LAMBDA: " << LAMBDA_NEW << endl;
        for(int i=0; i<order; i++) {
            cout << "x" << i+1 << " : " << eigenvector[i] << endl;
        }

    }while(abs(LAMBDA_NEW-LAMBDA_OLD) > TOLERANCE);

}

int main() {
    int order = 3;

    vector<vector<double>> one = read_matrix(order);

    cout << "Adios.." << endl;

    // Testing the guess_eigenvector
    vector<double> guess = read_guess_eigenvector(order);

    // Testing the power method
    power_method(one, guess, TOLERANCE, order);

    return 0;
}