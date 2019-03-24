# include <stdio.h>

void swap( int **a, int **b){

  int *temp = *a;
  *a = *b;
  *b = temp; 
}


int main(){

  int arr[3]= {1,2,3};
  int *ptr[3];
  int i;

  for(i=0; i<3; i++){
    ptr[i] = &arr[i];
	}
  printf("포인터 스왑 하기 전: \n");
  printf("arr[0]:%d , arr[1]:%d \n", arr[0], arr[1]);
  printf("ptr[0]:%d , ptr[1]:%d \n", *ptr[0], *ptr[1]);
  
  swap(&ptr[0], &ptr[1]);
  
  printf("\n");
  printf("포인터 스왑 한 후: \n");
  printf("arr[0]:%d , arr[1]:%d \n", arr[0], arr[1]);
  printf("ptr[0]:%d , ptr[1]:%d \n", *ptr[0], *ptr[1]);
  
  printf("포인터 변수가 스왑되는 거지 , 변수가 스왑되는 것이 아니다. [명심!] \n");

  return 0;
}
