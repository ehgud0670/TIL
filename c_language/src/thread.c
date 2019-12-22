# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

# define NUM 4

void *foo(void *arg){

	int local=0;
	int j;
	for(j=0; j<1000000; j++){
		++local; 
	}
	printf("local: %d \n", local);

	return 0;
}



int main(){
	int i;
	pthread_t *thread = (pthread_t*)malloc(sizeof(pthread_t)*NUM);

	for(i=0; i<NUM; i++){
		pthread_create(thread+i, NULL, foo, NULL);

	}

	for(i=0; i<NUM; i++){
		pthread_join(thread[i], NULL);

	}
	free(thread);

	return 0;
}
