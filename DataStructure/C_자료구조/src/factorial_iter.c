#include <stdio.h>


// for문 사용
int factorial_iter(int n){

  int i;
  int result = 1;
  for(i=1; i<=n; i++){
    result *= i;
	}
  
  return result;
}


int main(){

  int result = factorial_iter(4);
  printf("factorial_iter(4) is %d \n", result);

  return 0;
}
