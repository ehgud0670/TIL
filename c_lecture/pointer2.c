#include <stdio.h>

void swap(int* a , int* b){

  int temp = *a;
  *a=*b;
  *b=temp;

}


int main(){

  int num1=10, num2=20;

  swap(&num1,&num2);

  printf("num1=%d num2=%d \n", num1,num2);


  return 0;
}
