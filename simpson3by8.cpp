// Trapezoidal method to evaluate definite integral.
#include <iostream>
#include <cmath>
#include <vector>
#include <assert.h>
using namespace std;

enum FUNC {FIRST, SECOND, THIRD};
double func_val(double x, FUNC which_function) {
    double ans = 0;
    if (which_function == FIRST) {
        ans = 1/(double)(x+1);
    }
    else if (which_function == SECOND) {
        ans = 1/(double)(1+(x*x));
    }
    else {
        ans = x*x - 2;
    }
    return ans;
}

int main() {
    int N; // Number of strips, no. of data = n+1
    cout << "Enter the no of strips" << endl;
    cin >> N;
    double a, b;
    cout << "Enter the limits of integration a and b" << endl;
    cin >> a >> b;

    double strip_size = (b-a)/(double)N;

    double sum = func_val(a, FIRST) + func_val(b, FIRST);
    int m;
    for(int i=0; i<N-1; i++) {
        if (i%3 == 0) {
            m = 2;
        }else {
            m = 3;
        }

        double x = a + i * (strip_size);
        sum += m * func_val(x, FIRST);
    }


    assert(N > 1);
    sum *= 3 * strip_size/(double)(8);
   
    cout << "The sum is :" << sum << endl;

    return 0;
}