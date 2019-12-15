#include <stdio.h>

int factorial(int n){
  
  printf("factorial(%d)\n", n);
  
  if(n >= 300000){
   return 1;
	}
  
  return n*factorial(n+1);
}

int main(){

  int result = factorial(1);
  
  printf("factorial(3) is %d\n", result);

  return 0;
}
