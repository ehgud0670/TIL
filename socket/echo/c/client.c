#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){

	int sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1){
		perror("socket");
		return 1;
	}

	struct sockaddr_in saddr = {0, };
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr = inet_addr("127.0.1.1");
	saddr.sin_port = htons(5001);
	if(connect(sock,(struct sockaddr*)&saddr , sizeof saddr ) == -1){
		perror("connect");
		return 1;
	}
  
  char buf[128];
  while(1){
    int ret = read(0,buf,sizeof buf);
    write(sock,buf,ret);
    
    ret = read(sock, buf, sizeof buf); 
    // EOF = 0
    if(ret<=0)
    	break;

    write(1,buf,ret);
	}
}
