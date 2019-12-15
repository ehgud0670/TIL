#include <stdio.h>

int count;

int fibonacci(int n){
  int i; 
  int arr[n];
  for(i=1;i<=n;i++){
  	count++;
    if(i == 1 || i == 2 ){
      arr[i] = 1;
      continue;
		}
    arr[i] = arr[i-1] + arr[i-2];
	}

	return arr[n];

}

int main(){

  int result = fibonacci(10);
  printf("result: %d \n", result);
  printf("count: %d \n", count);
}
