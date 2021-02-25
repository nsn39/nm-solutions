#include <stdio.h>
#include <math.h>

double func(double x){
  return exp(x) + x - 3; 
}

double func_prime(double x){
  return exp(x) + 1; 
}

double newton_rhapson(double x0, double (*f)(double), double(*fp)(double), 
    double error){
  double x1 = x0 - (f(x0)/fp(x0));
  double rel_error = fabs(x1 - x0)/fabs(x1);
  printf("%.6lf\t%.6lf\t%.6lf\t%.6lf\t%.6lf\n",x0,f(x0),fp(x0),x1,rel_error);
  if (rel_error < error)
    return x1;

  return newton_rhapson(x1, f, fp, error);
}

int main(){
  double initial_guess, error;
  printf("For function e^x + x - 3 = 0 \n");  

  printf("Enter the initial_guess :");
  scanf("%lf",&initial_guess);
  printf("Enter the tolerable error :");
  scanf("%lf", &error);

  if (fabs(func_prime(initial_guess)) < 0.00001){
    fprintf(stderr, "Error : The first derivative is 0 at initial_guess.\n");
    return 1; 
  }
  printf("x0\t\tf(x0)\t\tf'(x0)\t\tx1\t\trel_error\n"); 
  double root = newton_rhapson(initial_guess, func, func_prime, error);
  printf("The root of the equation is : %lf\n", root);
  return 0;
}
