#include <stdio.h>
// 2,5,3,1
int get_max_recur(int *arr, int index ,int len){
  
  if(index == len -1){
    
    return arr[index];
	
	} else {
    
    int temp1 = arr[index];
    int temp2 = get_max_recur(arr, index + 1 ,len);
    
    return temp1 > temp2 ? temp1 : temp2;
	}
}


int main(){

  int arr[4] = {2,5,3,1};

  int result = get_max_recur(arr, 0, 4);

  printf("Max number is %d \n", result);

  return 0;
}
