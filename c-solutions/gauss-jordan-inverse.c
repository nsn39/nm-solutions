#include <stdio.h>

int main(){
  int n;
  printf("Enter the size of square matrix (n x n) :");
  scanf("%d",&n);
  double matrix[n][n+n];

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf("Element M[%d][%d] :", i+1, j+1);
      scanf("%lf", &matrix[i][j]);
    }
  }

  // creating augmented matrix
  for (int i=0; i<n; i++){
    for (int j=n; j<2*n; j++){
      if (i==j-n) 
        matrix[i][j] = 1;
      else 
        matrix[i][j] = 0;
    }
  }

  // gauss jordan elimination
  for(int i = 0; i < n; i++){
    for (int k = (i+1)%n; k != i ; k = (k+1)%n){
      double denominator = matrix[i][i];
      double numerator = matrix[k][i];
      if (denominator == 0){
        fprintf(stderr, "Error: Prinicpal diagonal element found to be zero\n");
        return 1;
      }
      double frac = numerator / denominator;
      for (int j = 0; j<2*n; j++){
        matrix[k][j] -= (frac * matrix[i][j]); 
      }
    }
  }

  for (int i=0; i<n; i++){
    for (int j = n; j < 2*n; j++){
      matrix[i][j] = matrix[i][j]/matrix[i][i];
    } 
  }

  printf("\n");
  printf("Inverse matrix is:\n");
  for (int i=0; i<n; i++){
    for (int j=n; j<2*n; j++){
      printf("%.6lf\t", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
