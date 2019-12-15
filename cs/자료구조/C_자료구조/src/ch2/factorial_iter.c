#include <stdio.h>


// for문 사용
int factorial_iter(int n){

  int i;
  int result = 1;
  for(i=n ;i>=1; i--){
    result *= i;
	}
  
  return result;
}


int main(){
  int num = 4;
  int result = factorial_iter(num);
  printf("factorial_iter(%d) is %d \n", num , result);

  return 0;
}
