# include <stdio.h>

int main(){

  int a = 5; 
  int *ptr1 = &a;

  char b = 'b';
  char *ptr2 = &b;

  double c = 4.7;
  double *ptr3 = &c;

  printf("a = %d \n", *ptr1);
  printf("b = %c \n", *ptr2);
  printf("c = %f \n", *ptr3);

  return 0;

}
