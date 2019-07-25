#include <stdio.h>

int add_step3(int n){

  if(n < 0 ){
    return 0;
	}

	return n + add_step3(n-3);

}

int main(){

  int result = add_step3(10);
  printf("add_step3_recur(10) is %d \n", result);

  return 0;
}
