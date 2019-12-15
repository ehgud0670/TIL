#include <stdio.h>

double sum_recur(int n){

  if( n == 1 ){
    return 1.0;
	}
  
  double num = (double)(1.0 / n);
  printf("%f \n", num);
  return num + sum_recur( n - 1 );
}

int main(){

  double result = sum_recur(3);
  printf("result is %f\n", result );
  return 0;
}
