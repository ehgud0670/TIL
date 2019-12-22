#include <stdio.h>

int main(void){
  
  int num =1;

  int result1 = num<<1; //num의 비트 열을 왼쪽으로 1칸 이동
  int result2 = num<<2; //num의 비트 열을 왼쪽으로 2칸 이동
  int result3 = num<<3; //num의 비트 열을 왼쪽으로 3칸 이동
  
  printf("origin: %d\n", num);
  printf("result1: %d\n", result1);
  printf("result2: %d\n", result2);
  printf("result3: %d\n", result3);
  return 0;
}
