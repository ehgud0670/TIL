#include <stdio.h>

int sum(int n){

  int sum = 0;

  int i;
  for( i = 1; i <= n; i++){
    sum += i;
	}
  return sum;
}

int main(){

  int result = sum(3);
  printf("result = %d\n", result);

  return 0;
}
