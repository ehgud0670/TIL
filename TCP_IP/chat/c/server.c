# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
int sd;
int current_num=0;
int sockArr[10];

// sock가 없을 수도 있고 겹칠 수도 있다. 


void* sendToAll(int *sock ){

  printf("sock:%d \n", *sock);
	while(1){
		char buf[128];
		int i;


		int ret = read(*sock, buf, sizeof buf);
		if( ret <=0){
			break;
		}
		for(i=0;i<current_num;i++){
			write(sockArr[i], buf, ret);
		}
	}
	close(*sock);
	close(sd);	
}


int main(){
	sd = socket(PF_INET, SOCK_STREAM, 0);
	if( sd == -1){
		perror("socket");
		return 1;
	}

	struct sockaddr_in saddr = {0,};
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = INADDR_ANY;
	saddr.sin_port = htons(5000);
	bind(sd, (struct sockaddr*)&saddr, sizeof saddr );

	listen(sd, SOMAXCONN);

	struct sockaddr_in caddr = { 0, };
	socklen_t caddrlen = sizeof caddr;
	pthread_t *thread = (pthread_t *)malloc(sizeof(pthread_t)*10);

	int i = 0;
	while(1){
    //int sock
		sockArr[i] = accept(sd, (struct sockaddr *)&caddr, &caddrlen);
		printf("%s\n",inet_ntoa(caddr.sin_addr));
                                                        //&sock
		pthread_create(thread+i, NULL, (void *)sendToAll, sockArr+i);
    //pthread_datach()
    i++;
		current_num++;
	}

	return 0;

}
