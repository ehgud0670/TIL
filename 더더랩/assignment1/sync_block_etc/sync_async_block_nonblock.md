## sync : 순서가 있는 것

## async : 순서가 없는 것

## block : 함수 호출시 함수가 행위( 리턴값 등등)을 다 할때까지 대기하는 것

## nonblock : 함수 호출시 함수가 행위를 다하지않아도 바로 리턴되어 다른 동작을 수행하는 것.


### c\_language examples


sync이면서 block<br>
```c
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

int main(){
	int fd;

	fd = creat("hello.txt", 0644);

	const char *buf = "My name is Doehyung!";
	ssize_t nr;

	nr = write(fd,buf, strlen(buf));
	if(nr == -1){
		perror("file");
	}


	return 0;
}
```

sync이면서 nonblock <br>
```c
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

int main(){
	int fd;
	char buf[BUFSIZ];
	ssize_t nr;

	fd = open("hello.txt", O_RDONLY, O_NONBLOCK);
	if(fd == -1){
		perror("file");
	}

	nr = read(fd,buf,BUFSIZ);
	if(nr == -1){
		if(errno == EAGAIN){
			printf("not read!\n");
			sleep(10);
			nr = read(fd,buf,BUFSIZ);
			if(nr == -1){
				perror("read");
			}
		}
		else{
			perror("read");
		}
	}

	printf("hello.txt: %s\n", buf);

	return 0;
}

```


async 이면서 block <br>
```c
void check(int signum){
	int status;
	while(wait(&staus)>0){
		printf("status: %d \n", status);
	}
}
```

async 이면서 nonblock <br>
```c
void check(int signum){
	int status;
	while(waitpid(0,&status ,WNOHANG) >0 ){
    printf("status: %d \n" ,status); 
	}
}
```


