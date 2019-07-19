#include <stdio.h>

# define NUM 5

int get_max_score(int *scores){

  int largest = scores[0];
  int i;
  for(i=1; i<NUM; i++){
    if(largest < scores[i]){
      largest = scores[i];
		}
	}

	return largest;

}

int main(){

  int scores[5] = {1,2,3,4,5};

  int largest = get_max_score(scores);

  printf("The largest score is %d \n", largest);

  return 0;
}
