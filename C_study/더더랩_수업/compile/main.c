# include <stdio.h>
int getNum(void);

void Increment(void);


int main(){

  printf("num: %d \n", getNum());
  Increment();
  
  printf("num: %d \n", getNum());
  Increment();
  
  printf("num: %d \n", getNum());


  return 0;
}
