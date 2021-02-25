#include <stdio.h>

double funcy1(double x, double y, double z){
  return x;
}

double funcz1(double x, double y, double z){
  return z+y;
}

int main(){
  double y_initial, x_initial, z_initial, h_interval, x_final;
  printf("For f(x) = x and g(x) = z+y :\n");

  printf("Enter initial values (x, y, z):");
  scanf("%lf %lf %lf", &x_initial, &y_initial, &z_initial);
  printf("Enter final value of x at which y and z are to be calculated:");
  scanf("%lf", &x_final);
  printf("Enter interval to be taken:"); 
  scanf("%lf", &h_interval);

  double k1, k2, k3, k4, l1, l2, l3, l4;
  printf("x\t\ty\t\tz\t\tyn\t\tzn\n");
  while (x_initial < x_final){
    k1 = h_interval * funcy1(x_initial, y_initial, z_initial);
    l1 = h_interval * funcz1(x_initial, y_initial, z_initial);

    k2 = h_interval * funcy1(x_initial + 0.5 * h_interval, 
        y_initial + 0.5 * k1, z_initial + 0.5 * l1);
    l2 = h_interval * funcz1(x_initial + 0.5 * h_interval, 
        y_initial + 0.5 * k1, z_initial + 0.5 * l1);

    k3 = h_interval * funcy1(x_initial + 0.5 * h_interval, 
        y_initial + 0.5 * k2, z_initial + 0.5 * l2);
    l3 = h_interval * funcz1(x_initial + 0.5 * h_interval, 
        y_initial + 0.5 * k2, z_initial + 0.5 * l2);

    k4 = h_interval * funcy1(x_initial + h_interval, 
        y_initial + k3, z_initial + l3);
    l4 = h_interval * funcz1(x_initial + h_interval, 
        y_initial + k3, z_initial + l3);

    printf("%lf\t%lf\t%lf\t", x_initial, y_initial, z_initial);
    y_initial += (1.0/6) * (k1 + 2*k2 + 2*k3 + k4);
    z_initial += (1.0/6) * (l1 + 2*l2 + 2*l3 + l4);
    x_initial += h_interval;
    printf("%lf\t%lf\n", y_initial, z_initial);
  }
  printf("The value of y at x=%lf is : %lf\n", x_final, y_initial);
  printf("The value of z at x=%lf is : %lf\n", x_final, z_initial);
  return 0;
}
