#include <stdio.h>
#include <time.h>

// double power( double x , int n ){
//  
//  if( n <= 0 ){
//    return 1;
//	}
//	return x * power(x , n-1);
//
// }

double power( double x , int n ){

  if( n == 1){
    return x;
	} else if ( n % 2 == 0 ){
    return power( x*x , n / 2 );
	} else {
    return x * power( x*x , (n-1) / 2 );
	}

}


int main(){

  clock_t start;
  clock_t stop;
  
  start = clock();
  double result = power( 2.0 , 1000000 );
  printf("2^10 is %g \n", result); 
  stop = clock();

  double duration = (double)( stop - start ) / CLOCKS_PER_SEC;
  printf("duration = %f \n", duration);
  return 0;
}
