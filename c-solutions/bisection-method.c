#include <stdio.h>
#include <math.h>

double func(double x){
  return x + log(x); 
}

double bisection_method(double x0, double x1, double (*f)(double), double err){
  double x2 = (x0 + x1) /2;
  printf("%.6lf\t%.6lf\t%.6lf\t%.6lf\n", x0, x1, x2, f(x2));

  if (fabs(f(x2)) < err)
    return x2;

  if (f(x0) * f(x2) < 0)
    return bisection_method(x0, x2, f, err);
    
  return bisection_method(x2, x1, f, err);
}

int main(){
  double lower_guess, upper_guess, error;
  printf("For function x + log(x) :\n");  

  printf("Enter the (lower_guess, upper_guess) :");
  scanf("%lf %lf",&lower_guess, &upper_guess);
  printf("Enter the tolerable error :");
  scanf("%lf", &error);

  if (func(lower_guess) * func(upper_guess) > 0){
    fprintf(stderr, "Error: Incorrect initial guesses.\n"); 
    return 1;
  }

  printf("x0\t\tx1\t\tx2\t\tf(x2)\n");
  double root = bisection_method(lower_guess, upper_guess, func, error);
  printf("The root of the equation is : %lf\n", root);
  return 0;
}
