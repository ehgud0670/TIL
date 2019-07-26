#include <stdio.h>
#include <time.h>

int fib_iter_time(int n){

	if( n == 0 ){
		return  0;
	} 
	if( n == 1 ){
		return  1;
	}

	int target;
	int pp = 0;
	int p = 1;

	int i;
	for( i = 2 ; i <= n ; i++ ) {
		target = pp + p;
		pp = p;
		p = target;
	}
	return target;
}
// 0 , 1 , 1 , 2, 3, 5 
int main(){
  clock_t start;
  clock_t stop;
  double duration; 

  start = clock(); // 측정 시작 
  int num = 35;
  int result = fib_iter_time(num);
  printf("fib_iter(%d) is %d \n", num , result );
  
  stop = clock(); // 측정 종료 
  duration = (double)(stop - start) / CLOCKS_PER_SEC;
  printf("수행시간은 %f초입니다. \n", duration);

	return 0;
}
