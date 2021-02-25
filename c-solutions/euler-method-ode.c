#include <stdio.h>
#include <math.h>

double func(double x, double y){
  return sin(x) + cos(y);
}

int main(){
  double y_initial, x_initial, h_interval, x_final;
  printf("For the function f(x) = sin(x)+cos(y) :\n");

  printf("Enter initial values (x, y):");
  scanf("%lf %lf", &x_initial, &y_initial);
  printf("Enter interval to be taken:"); 
  scanf("%lf", &h_interval);
  printf("Enter final value of x at which y is to be calculated:");
  scanf("%lf", &x_final);

  // y_new = old_y + h * func(old_x, old_y)
  while (x_initial + h_interval < x_final){
    printf("%g\t%g\t%g\t", x_initial, y_initial, func(x_initial, y_initial));
    y_initial += h_interval * func(x_initial, y_initial); 
    printf("%g\n", y_initial);
    x_initial += h_interval;
  }
  printf("The value of y at x=%lf is : %lf\n", x_final, y_initial);
  return 0;
}
