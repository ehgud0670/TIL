# include <stdio.h>
# include <stdlib.h>

int main(){

  int *ptr =(int*)malloc(sizeof(int));
  *ptr = 2;

  printf("%d \n", *ptr);
  free(ptr);
  printf("%d \n", *ptr); //메모리 공간이 없어졌으므로 NULL값(0) 반환
  
  printf("pointer:%d \n", ptr); // 초기화 하지 않으면 똥값으로 표현된다. 
  ptr = NULL; //NULL 포인터로 초기화
  printf("pointer:%d \n", ptr); //NULL로 초기화 했으므로 NULL값(0) 반환
  return 0;
}
