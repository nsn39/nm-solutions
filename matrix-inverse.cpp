// Finding inverse of a matrix using gauss-jordan method
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<double>> read_and_augment_matrix(int order) {
    vector<vector<double>> ans(order, vector<double>(2*order,0));

    for(int i=0; i<order; i++) {
        for(int j=0; j<order; j++) {
            cout << "Enter M" << i << "," << j  << ": " << endl;
            cin >> ans[i][j];
        }

        // Augmenting the matrix
        for(int j=order; j<2*order; j++) {
            if (j == order+i) {
                ans[i][j] = 1;
            }else {
                ans[i][j] = 0;
            }
        }
    }
    return ans;
}

void invert_matrix(vector<vector<double>> matrix, int order) {
    // Applying gauss-elimination on augmented matrix
    
    cout << "Matrix size:" <<  matrix.size() << endl;
    cout << "Sub size: " << matrix[0].size() << endl;
    cout << matrix[1][2] << endl;
    cout << matrix[1][4] << endl;

    for(int i=0; i<order; i++) {
        if (matrix[i][i] == 0) {
            cout << "Mathematical error." << endl;
            return;
        }

        
        for(int j=0; j<order; j++) {
            if (i != j) {
                
                double ratio = matrix[j][i]/(double)matrix[i][i];

                
                 for(int k=0; k<2*order; k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
 
            }
        }
        
    }
    
    // Row operation to convert principal diagonal to 1
    for(int i=0; i<order; i++) {
        for(int j=order; j<2*order; j++) {
            matrix[i][j] /= (double)matrix[i][i];
        }
    }
    
    // Displaying the inverse matrix
    for(int i=0; i<order; i++) {
        for(int j=order; j<2*order; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main() {
    int order = 3;

    // Testing the read_matrix function
    vector<vector<double>> matrix = read_and_augment_matrix(order);

    invert_matrix(matrix, order);
    return 0;
}