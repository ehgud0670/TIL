#include <stdio.h>

int get_sum(int n){

  int sum = 0;
  int i;
  for( i = 0; i < n; i++){
    sum += i;
  }

  return sum;
}

int main(){

  int result = get_sum(10);

  printf("result is %d \n", result);


  return 0;
}
