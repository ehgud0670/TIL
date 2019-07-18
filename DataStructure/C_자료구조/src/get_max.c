#include <stdio.h>

int get_max(int a , int b){


  return  a > b ? a : b ;
  
}

// 삼항 연산자의 예시 return a > b ? a : b ;

int main(){

  int result = get_max(3,5);
  printf("result is %d \n", result);

  return 0;
}
