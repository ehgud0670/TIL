#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  clock_t start;
  clock_t stop;
  double duration;

  start = clock();

  int i;
  for(i=0; i < 1000000; i++);

  stop = clock();

  duration = (double)(stop - start) / CLOCKS_PER_SEC;
  printf("수행시간은 %f초입니다.\n", duration);

  return 0;
}
