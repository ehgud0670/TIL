# include <stdio.h>


struct A{
 char a;
 char b;
 char c; 
};
struct B{
 char c;
 int a;
 double b; 
};

int main(void){

  printf("%ld \n", sizeof(struct A));
  printf("%ld \n", sizeof(struct B));


  return 0;
}
