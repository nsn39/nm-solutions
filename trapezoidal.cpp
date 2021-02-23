// Trapezoidal method to evaluate definite integral.
#include <iostream>
#include <cmath>
#include <vector>
#include <assert.h>
using namespace std;


int main() {
    int N; // Number of strips, no. of data = n+1
    cout << "Enter the no of strips" << endl;
    cin >> N;
    double a, b;
    cout << "Enter the limits of integration a and b" << endl;
    cin >> a >> b;

    vector<double> y_values(N+1);

    for(int i=0; i<=N; i++) {
        cout << "Enter Y" << i+1 << " ";
        cin >> y_values[i];
    }

    double strip_size = (b-a)/(double)N;

    assert(N > 1);
    double sum = y_values[0] + y_values[N-1];

    for(int i=1; i<=N-1; i++)
        sum += 2 * y_values[i];   

    sum *= (strip_size)/(double)2;

    cout << "The sum is :" << sum << endl;

    return 0;
}