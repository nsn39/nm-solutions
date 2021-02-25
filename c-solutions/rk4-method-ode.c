#include <stdio.h>
#include <math.h>

double func1(double x, double y){
  return sin(x) + y;
}

int main(){
  double y_initial, x_initial, h_interval, x_final;
  printf("For f(x) = sin(x) + y :\n");

  printf("Enter initial values (x, y):");
  scanf("%lf %lf", &x_initial, &y_initial);
  printf("Enter interval to be taken:"); 
  scanf("%lf", &h_interval);
  printf("Enter final value of x at which y is to be calculated:");
  scanf("%lf", &x_final);

  double k1, k2, k3, k4;
  printf("x\t\ty\t\tyn\n");
  while (x_initial < x_final){
    k1 = h_interval * func1(x_initial, y_initial);
    k2 = h_interval * func1(x_initial + 0.5 * h_interval, 
        y_initial + 0.5 * k1);
    k3 = h_interval * func1(x_initial + 0.5 * h_interval, 
        y_initial + 0.5 * k2);
    k4 = h_interval * func1(x_initial + h_interval, y_initial + k3);

    printf("%lf\t%lf\t", x_initial, y_initial);
    y_initial += (1.0/6) * (k1 + 2*k2 + 2*k3 + k4);
    x_initial += h_interval;
    printf("%lf\n", y_initial);
  }
  printf("The value of y at x=%lf is : %lf\n", x_final, y_initial);
  return 0;
}
