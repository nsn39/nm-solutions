#include <stdio.h>
#include <math.h>

double func3(double x){
  return pow(3,x) + x*tan(x);
}

int main(){
  double upper_limit, lower_limit;
  int sub_intervals;

  printf("For function 3^x + x*tan(x):\n");
  printf("Enter the (upper_limit, lower_limit) for integration :");
  scanf("%lf %lf", &upper_limit, &lower_limit);
  printf("Enter the number of sub-intervals :");
  scanf("%d", &sub_intervals);

  if (sub_intervals % 3 != 0){
    fprintf(stderr, "Number of sub-intervals must be a multiple of 3.\n");
    return 1;
  }

  double step = (upper_limit - lower_limit)/sub_intervals;
  double integrate_value = func3(lower_limit) + func3(upper_limit);
  lower_limit += step;
  int index_count = 1;
  printf("x\t\ty=f(x)\n");
  while(lower_limit < upper_limit){
    if (index_count % 3 == 0)
      integrate_value += 2 * func3(lower_limit);
    else 
      integrate_value += 3 * func3(lower_limit);

    printf("%lf\t%lf\n",lower_limit, func3(lower_limit));
    lower_limit += step;
    index_count++;
  }
  integrate_value *= (3.0/8) * step;
  printf("The value of integration is : %lf\n", integrate_value);
  return 0;
}
