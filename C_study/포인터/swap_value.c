#include <stdio.h>

void swap(int a , int b){

  int temp;
  temp = a;
  a = b;
  b = temp;
}


int main(){


  int a = 3;
  int b = 5;

  printf("before swap\n");
  printf("a: %d , ", a);
  printf("b: %d \n", b);

  swap(a,b);
  printf("after swap\n");
  printf("a: %d , ", a);
  printf("b: %d \n", b);
  return 0;
} 
