# include <stdio.h>

int sum(int n){
  printf("%d\n", n);
  if( n < 1 ) return 1;
  else return ( n + sum( n-1 ) ) ;

}


int main(){
  
  int result = sum(5);
  printf("result is %d \n", result );

  return 0;
}
