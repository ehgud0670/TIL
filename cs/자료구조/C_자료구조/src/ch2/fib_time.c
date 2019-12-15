#include <stdio.h>
#include <time.h>

int fib_time(int n){

  if( n == 0 ){
    return 0;
	}
	if( n == 1 ){
    return 1;
	}

	return fib_time(n-1) + fib_time(n-2);
}

int main(){
  int num = 35;
  
  clock_t start;
  clock_t stop;
  double duration;
  
  start = clock(); // 측정 시작

  int result = fib_time(num);
  printf("fib(%d) is  %d \n", num , result );
  
  stop = clock(); // 측정 종료
  duration = (double)(stop - start) / CLOCKS_PER_SEC;
  printf("수행시간은 %f초입니다. \n", duration);

  return 0;
}
