# include <stdio.h>

int main(void){

  const int max=1;// 심볼릭 상수 max를 1로 초기화.
  max=2; //값을 재할당(assign) 했으므로 컴파일 에러 발생. 상수는 read-only variable이다. 

  return 0;
}
