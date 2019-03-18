# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX 10000
# define NUM 1000

int main(){

  char *header=(char*)malloc(sizeof(char)*MAX);
  char *str[NUM];
  char word[MAX];
  int count=0;
  int i;


  fgets(header,MAX,stdin);
  printf("%s", header);

  
  count = 0 ;
  while(fgets(word,MAX, stdin) != NULL){
    str[count] =(char*)malloc(sizeof(char)*MAX);
    strcpy(str[count],word);
    count++;
	}
  for(i=0; i<count; i++)
    printf("%s", str[i]);
  printf("\n");

  printf("총 %d개의 데이터가 로드되었습니다.\n", count);  
  
  free(header);
  for(i=0; i<count; i++)
    free(str[i]);

  return 0;
}
