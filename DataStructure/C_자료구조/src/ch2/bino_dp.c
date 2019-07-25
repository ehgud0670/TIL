// 이항계수 DP
#include <stdio.h>
#define MAX 100  

int count = 0;
int arr[MAX][MAX];

int bino_dp(int n, int k){
  count++;
	if(k == 0 || k == n ){
		arr[n][k] = 1;
		return arr[n][k];

	} 

	if(arr[n][k] != 0){
		return arr[n][k];
	} 

  arr[n][k] = bino_dp(n-1 , k-1) + bino_dp(n-1, k);
  return arr[n][k];
}

int main(){
  int num = 64;
  int result = bino_dp(num,2);
  printf("%dC2 = %d \n", num, result);
  printf("count: %d \n", count);

	return 0;
}
