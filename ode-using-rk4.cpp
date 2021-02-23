// Euler's method to solve 1st order ODE
#include <iostream>
#include <cmath>

using namespace std;

enum FUNC {FIRST, SECOND, THIRD};
double func_val(double x, double y, FUNC which_function) {
    double ans = 0;
    if (which_function == FIRST) {
        ans = x + y;
    }
    else if (which_function == SECOND) {
        ans = y - x;
    }
    else {
        ans = x*x + y*y;
    }
    return ans;
}


int main() {
    double X, Y, final_X;
    cout << "Enter the initial conditions x0 and y0:" << endl;
    cin >> X >> Y;
    cout << "Enter the value of final X" << endl;
    cin >> final_X;
    int N;
    cout << "Enter the no. of stripes" << endl;
    cin >> N;

    double step_size = (final_X - X)/(double)N;

    double sum_X = X, sum_Y = Y;
    for(int i=0; i<N; i++) {

        double k1 = step_size * func_val(sum_X, sum_Y, SECOND);
        double k2 = step_size * func_val(sum_X+(step_size/(double)2), sum_Y+(k1/(double)2), SECOND);
        double k3 = step_size * func_val(sum_X+(step_size/(double)2), sum_Y+(k2/(double)2), SECOND);
        double k4 = step_size * func_val(sum_X+step_size, sum_Y+k3, SECOND);

        double k = (k1+(2*k2)+(2*k3)+k4)/(double)6;

        sum_X += step_size;
        sum_Y += k;

        cout << "x = " << sum_X << " y = " << sum_Y << endl;
    }

    return 0;
}