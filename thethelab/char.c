# include <stdio.h>

int main(){

  char *opt = "hello"; // 문자열은 처음 주소값을 나타내므로(decay), 이는 합당하다.
  //int *num =2; (x)

	printf("%s \n", opt);
  //printf("%d \n", *num);

  return 0;
}
