#include <stdio.h>

int recur(int n){

  if( n != 1 )  recur(n-1);
  printf("%d\n", n);

}

int main(){

  recur(5);

  return 0;
}
