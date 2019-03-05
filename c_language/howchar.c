
# include <stdio.h>

int main(void){

  char ch1 = 'A', ch2 =65; // ch1과 ch2에 저장되는 값은 동일하다.
  char ch3 = 'a', ch4 =97; // ch3와 ch4에 저장되는 값은 동일하다.
  
  printf(" %c %d \n",ch1,ch1);
  printf(" %c %d \n",ch2,ch2);
  printf(" %c %d \n",ch3,ch3);
  printf(" %c %d \n",ch4,ch4);

  return 0;
}
