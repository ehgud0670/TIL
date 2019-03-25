# include <stdio.h>
int absolute(int a, int b);

int main(){

  int a,b;
  int result;

  printf("두 수를 입력해주세요: ");
  scanf("%d %d", &a,&b);

  result = absolute(a,b);

  printf("두 수의 절대값은 %d 입니다. \n", result);

  return 0;
}
