# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>


# define THREADS 3

__thread int tls; //TLS
int global;

void* func(void *arg){
  int num = (int)arg;
  tls = num; // TLS변수인 tls에 num 할당.
  global = num;// 전역변수인 global에 num 할당.  
  sleep(1);
  printf("Thread=%d tls=%d global = %d\n", num, tls, global); 
}



int main(){

	int ret;
	pthread_t thread[THREADS];
	int num;

  //pthread_create()
	for(num=0; num<THREADS; num++){
		//ret의 값이 0이 아니면 pthread_create가 오류난것이다. 
		ret = pthread_create(&thread[num], NULL, &func, (void*)num);
		if(ret){
			printf("error pthread_create\n");
			exit(1);
		}
	}

  //pthread_join()
  for(num = 0; num <THREADS; num++){
    ret = pthread_join(thread[num],NULL);
    if(ret){
      printf("error pthread_join\n");
      exit(1);
		}
	}

	return 0;
}
