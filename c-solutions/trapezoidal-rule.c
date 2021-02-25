#include <stdio.h>
#include <math.h>

double func1(double x){
  return pow(3,x); 
}

int main(){
  double upper_limit, lower_limit;
  int sub_intervals;

  printf("For function 3^x :\n");
  printf("Enter the (upper_limit, lower_limit) for integration :");
  scanf("%lf %lf", &upper_limit, &lower_limit);
  printf("Enter the number of sub-intervals :");
  scanf("%d", &sub_intervals);

  double step = (upper_limit - lower_limit)/sub_intervals;
  double integrate_value = func1(lower_limit) + func1(upper_limit);
  lower_limit += step;
  printf("x\t\ty=f(x)\n");
  while(lower_limit < upper_limit){
    printf("%lf\t%lf\n",lower_limit, func1(lower_limit));
    integrate_value += 2 * func1(lower_limit);
    lower_limit += step;
  }
  integrate_value = 0.5 * step * integrate_value;
  printf("The value of integration is : %lf\n", integrate_value);
  return 0;
}
