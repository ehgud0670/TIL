# include <stdio.h>

int main(void){

  int num1=1, num2=3;

  // num1은 0000 0001이고, num2은 0000 0011이다.
  
  // 비트 연산자 AND, OR, XOR : & ,| ,^
  printf("비트 AND : %d \n", num1 & num2); // 01 & 11 = 01
  printf("비트 OR: %d \n", num1 | num2); // 01 | 11 = 11
  printf("비트 XOR: %d \n", num1 ^ num2); // 01 ^ 11 = 10

  return 0;

}
