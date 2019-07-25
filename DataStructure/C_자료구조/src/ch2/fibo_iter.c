#include <stdio.h>

int fibo_iter(int n){
	if( n == 0 ){

		return 0;

	} else if( n == 1 ){

		return 1;

	} else {
		int pp = 0;
		int p = 1;

		int target = 0;
		int i;
		for( i = 2 ; i <= n ; i++){
			target = pp + p;
			pp = p;
			p = target;
		}
		return target;

	}
}


int main(){
  int num = 6;
  int result = fibo_iter(num);
  printf("fibo_iter(%d) is %d \n", num , result);

	return 0;
}
