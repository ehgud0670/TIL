#include <stdio.h>

int recur(int n){

  printf("%d \n", n);
  if( n < 1 ) return -1;
  else return ( recur(n-3) + 1);
}

int main(){

  int result = recur(10);
  printf("result is %d \n", result );

  return 0;
}
