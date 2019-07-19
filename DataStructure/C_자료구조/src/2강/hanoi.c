# include <stdio.h>
int count = 0 ;
long long hanoi(int n){
  count++;
  if( n == 1 ){
    return 1;
	}
	return 1 + 2 * hanoi(n-1); 
}

int main(){

  int num = 10;
  long long result = hanoi(num);
  printf("hanoi(%d) is %lld \n", num , result ) ;
  printf("count = %d \n", count );

  return 0;
}
