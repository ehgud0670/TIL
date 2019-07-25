// fibonacci recur 방식은 O(2^n)이다.

#include <stdio.h>
int count = 0;

int fib(int n){
  ++count;
  
  if( n == 0 ){
    return 0;
	} else if ( n == 1 ){
    return 1;
	} else {
    return fib(n-1) + fib(n-2);
	}
}

int main(){

  int result = fib(30);
  printf( "result is %d \n", result );
  printf( "count is %d \n", count );

  return 0;
}
