#include <stdio.h>

void addTen(int *arr){

  int i;
  for(i =0; i<3; i++){
    arr[i] += 10;
  }

  printf("addTen()에서: sizeof(arr): %ld\n", sizeof(arr));

}


int main(){
  
  int i; 
  int arr[3] = { 1, 2, 3 };

  printf("main()에서: sizeof(arr): %ld\n", sizeof(arr));

  addTen(arr); // 배열의 이름을 매개값으로. 즉 포인터로서 보냄.

  for(i = 0; i < 3; ++i){
    printf("%d\n", arr[i]);
  }  

  return 0;
}
