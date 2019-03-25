# include <stdio.h>
# include "add.h"

int main(){

  int a;
  int b;
  int result;

  printf("숫자 두개를 입력해주세요: ");
  scanf("%d %d", &a ,&b);

  result = add(a,b);

  printf("result: %d \n",result);

  return 0;
}
