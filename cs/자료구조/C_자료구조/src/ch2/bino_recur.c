// 이항계수 재귀 함수
#include <stdio.h>

int count = 0;

int bino_recur(int n, int k){
 
 count++;
 
 if(k == 0 || k == n){
   return 1;
 }

 return bino_recur(n - 1, k - 1) + bino_recur(n - 1 , k);


}

int main(){
  int num = 64;
  int result = bino_recur(num,2);
  printf("%dC2 = %d \n", num, result );
  printf("count = %d \n", count );
  return 0;
}
