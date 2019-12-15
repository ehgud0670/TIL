#include <stdio.h>
#include <time.h>

double slow_power(double x , int n){

  int i;
  double result = 1.0;
  for( i = 0 ; i < n ; i++ ){
    result *= x;
	}

	return result;

}

int main(){
  clock_t start;
  clock_t stop;
  
  start = clock();  
  double result = slow_power(2,1000000);
  printf("2^10 is %g \n" , result);
  stop = clock();


  double duration = (double)(stop - start)/CLOCKS_PER_SEC;
  printf("duration is %f \n", duration);
  return 0;
}
