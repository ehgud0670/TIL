#include <stdio.h>

int sum_recur(int n){
  if( n == 1){
    return 1;
	}
	return n + sum_recur(n-1);

}

int main(){

	printf("result is %d \n", sum_recur(10));
  
  return 0;
}
