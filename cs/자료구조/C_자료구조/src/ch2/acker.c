#include <stdio.h>
int count = 0;

// 근데 사실 이것도 재귀함수이긴 하다.dp도 아니다. 
// 이 함수는 acker_recur.c 보다는 2배 효율이 좋은 알고리즘으로 이것도 역시 중복 호출을 무지막지 하게 한다.
int acker(int m, int n){  
  count++;
  while( m != 0){
    if( n != 0){
      n = acker(m, n-1);
      m = m - 1;
		} else {
      m = m - 1;
      n = 1;
		}
	}

	return n + 1;
}

int main(){

	int m = 3;
	int n = 8;
	int result = acker(m,n);
	printf("A(%d,%d) = %d \n", m,n, result);
	printf("count: %d\n", count);
	return 0;
}
