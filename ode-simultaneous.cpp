// Euler's method to solve simultaneous 1st order ODEs.
#include <iostream>
#include <cmath>

using namespace std;

enum FUNC {FIRST, SECOND, THIRD};
double func_val(double x, double y, double z, FUNC which_function) {
    double ans = 0;
    if (which_function == FIRST) {
        ans = y - 3*z;
    }
    else if (which_function == SECOND) {
        ans = 2*y + z;
    }
    else {
        ans = x*x + y*y;
    }
    return ans;
}


int main() {
    double X, Y , Z, final_X;
    cout << "Enter the initial conditions x0, y0 and z0:" << endl;
    cin >> X >> Y >> Z;
    cout << "Enter the value of final X" << endl;
    cin >> final_X;
    int N;
    cout << "Enter the no. of stripes" << endl;
    cin >> N;

    double step_size = (final_X - X)/(double)N;

    double sum_X = X, sum_Y = Y, sum_Z = Z;
    for(int i=0; i<N; i++) {

        double k1 = step_size * func_val(sum_X, sum_Y, sum_Z, SECOND);
        double l1 = step_size * func_val(sum_X, sum_Y, sum_Z, FIRST);

        double k2 = step_size * func_val(sum_X+(step_size/(double)2), sum_Y+(k1/(double)2),sum_Y+(l1/(double)2), SECOND);
        double l2 = step_size * func_val(sum_X+(step_size/(double)2), sum_Y+(k1/(double)2),sum_Y+(l1/(double)2), FIRST);
      
        double k3 = step_size * func_val(sum_X+(step_size/(double)2), sum_Y+(k2/(double)2), sum_Z+(l2/(double)2),SECOND);
        double l3 = step_size * func_val(sum_X+(step_size/(double)2), sum_Y+(k2/(double)2), sum_Z+(l2/(double)2),FIRST);
    
        double k4 = step_size * func_val(sum_X+step_size, sum_Y+k3, sum_Z+l3, SECOND); 
        double l4 = step_size * func_val(sum_X+step_size, sum_Y+k3, sum_Z+l3, FIRST);

        double k = (k1+(2*k2)+(2*k3)+k4)/(double)6;
        double l = (l1+(2*l2)+(2*l3)+l4)/(double)6;

        sum_X += step_size;
        sum_Y += k;
        sum_Z += l;

        cout << "x = " << sum_X << " y = " << sum_Y << " z = " << sum_Z << endl;
    }

    return 0;
}