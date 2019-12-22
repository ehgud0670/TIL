# include <stdio.h>

int main(void){
 
  FILE * fp = fopen("data.txt", "w+");

  if(fp == NULL){
    printf("파일 에러 \n");
    return -1; // 비정상 종료를 알리기 위해서 -1을 반환함
  }
  
  fprintf(fp, "hello everyone");
  fclose(fp);

  return 0;
}
