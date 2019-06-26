#include <stdio.h>

int count = 0;
int fibonacci(int n){

  if(n == 1 || n == 2){
    count++;
    return 1;
	} else {
		count++;
    return  fibonacci(n-1) + fibonacci(n-2);   
	}
}


int main(void){

  int result = fibonacci(10); 
  printf("result: %d \n", result);
  printf("count: %d \n", count);

  return 0;
}
