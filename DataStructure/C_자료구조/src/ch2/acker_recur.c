#include <stdio.h>

int count = 0;

int acker_recur(int m , int n){
  count++;
  
  if( m == 0 ){
    return n + 1;
	}

	if( n == 0 ){
    return acker_recur(m-1, 1);
	}

	return acker_recur( m-1 , acker_recur(m, n-1)); 

}


int main(){
	int m = 2;
	int n = 3;
  int result = acker_recur(m,n);
  printf("A(%d,%d) = %d \n", m,n, result);
  printf("count: %d\n", count);
  return 0;
}
