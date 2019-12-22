# include <stdio.h>

# define SQUARE(X) X*X

int main(void){

  int num=20;
  
  // 정상적 결과 출력
  printf("%d \n", SQUARE(num));
  printf("%d \n", SQUARE(-1));

  // 비정상적 결과 출력
  printf("%d \n",SQUARE(3+2)); //선행처리기는 단순치환이기 때문에 3+2*3+2로 치환되기 때문에 
  // 결과는 25가 아니라 11이 된다. 따라서 이런 경우는 SQUARE((3+2))로 코드를 작성해야 (3+2)*(3+2)가 되어
  // 결과가 25로 잘 나온다.
  printf("%d \n",SQUARE((3+2)));
  return 0; 
}
