#include <stdio.h>

int count;

int f[10];
int fibonacci_memo(int n){
  
  if(f[n] != 0){
    return f[n];
	} else {
    count++;    
    if(n == 1 || n == 2){
      f[n] = 1;
		} else{
      f[n] = fibonacci_memo(n-1) + fibonacci_memo(n-2);
		}
	}
  return f[n];
}


int main(){

  int result = fibonacci_memo(10);
  printf("result: %d \n", result);
  printf("count: %d \n", count);
 

  return 0;
}
