#include <stdio.h>

void swap(int *ptr1 , int *ptr2){

  int temp;
  temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}


int main(){


  int a = 3;
  int b = 5;

  printf("before swap\n");
  printf("a: %d , ", a);
  printf("b: %d \n", b);

  swap(&a,&b);
  printf("after swap\n");
  printf("a: %d , ", a);
  printf("b: %d \n", b);
  return 0;
} 
