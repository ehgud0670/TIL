# include <stdio.h>

# define ADD 1
# define MIN 0 

int main(void){

  int num1,num2;
  printf("두 개의 정수 입력: num1, num2\n");
  scanf("%d %d", &num1,&num2);

  # if ADD
    printf("%d + %d = %d \n", num1,num2,num1+num2);


  # endif

  # if MIN
    printf("%d - %d = %d \n", num1,num2,num1-num2);

  # endif
  return 0;
}
