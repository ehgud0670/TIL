#include <stdio.h>

int add_step3_iter(int n){
  
  int sum = 0;
  int i;
  for( i = n ; i > 0; i-=3){
    sum += i;
	}

	return sum;
  // 10 + 7 + 4 + 1 = 22. 
}

int main(){

  int result = add_step3_iter(10);
  printf("add_step3_iter(10) is %d \n", result);

  return 0;
}
