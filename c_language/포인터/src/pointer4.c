#include <stdio.h>

void addTen(int (*arr)[3]){
  int i;
  for( i = 0; i < 3; ++i){
    (*arr)[i] += 10;
	}

  // *arr  
  // int arr[3]
  printf("addTen에서 arr의 size: %ld\n", sizeof(arr));
}

int main(){

  int i;
  int arr[3] = { 1, 2, 3};

  addTen(&arr);
  // int[3]* p = &arr;
  // int (*p)[3] = &arr;

  for( i = 0; i < 3; ++i){
    printf("%d\n", arr[i]);
	}
  return 0;
}
