# include <stdio.h>

int num = 0;

void Increment(){

  num++;
}

int  getNum(){

  return num;
}


int main(void){

  printf("num: %d \n", getNum());
  Increment();
  
  printf("num: %d \n", getNum());
  Increment();
  
  printf("num: %d \n", getNum());

  return 0;
}
