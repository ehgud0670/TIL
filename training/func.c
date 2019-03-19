#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "func.h"

# define ROW 400
# define COL 15
# define MAX 10000
# define WORD_SIZE 100



int set_Head(int *name, Kind *kind, int *RP, int *DC ,int *ES, int *weight, int *width  ){
  int i;
  int j; 
  int head_count;
  char *head[COL];
  char *ptr;
  char *del;
  char *header=(char*)malloc(sizeof(char)*MAX);


  fgets(header,MAX,stdin);

  head_count=0;
  ptr = strtok(header,",");
  while(ptr != NULL){
    head[head_count] = (char*)malloc(sizeof(char)*20);
    del =  strchr(ptr, '\r');
    if(del)
    	*del = 0;
    del = strchr(ptr, '\n');
    if(del)
    	*del =0;

    strcpy(head[head_count],ptr);
    ++head_count;
    ptr = strtok(NULL,",");// NULL이다!
	}
  free(header);

  j=0;
  for(i=0; i<head_count; i++){
    if(strcmp(head[i],"Vehicle Name")==0)
        *name = i;
    else if(strcmp(head[i],"Retail Price")==0)
    	  *RP = i;
    else if(strcmp(head[i],"Dealer Cost")==0)
    	  *DC = i;
    else if(strcmp(head[i],"EngineSize")==0)
        *ES = i;
    else if(strcmp(head[i],"Weight")==0)
        *weight = i;
    else if(strcmp(head[i],"Width")==0)
        *width = i;
    else{
       kind[j].idx = i;
       strcpy(kind[j].name, head[i]);
       j+=1;
		}	
  }
  free_arr(head,head_count);
  return j;
}

void free_arr(char **arr,int len ){

  int i;
  for(i=0; i<len; i++)
    free(arr[i]);
}

int set_Car(Car *car,int name,Kind *kind,int kcount,int RP,int DC,int ES,int weight,int width){
  char *str[ROW];
  int car_count;
  int i;
  int word_count;
  char *ptr;
  char *del;
  char string[MAX];

  car_count = 0;
  while(fgets(string,MAX, stdin) != NULL){
    str[car_count] =(char*)malloc(sizeof(char)*MAX);
    strcpy(str[car_count],string);
    car_count++;
	}

  char *word[car_count][COL];
  // str 자르기
  for(i=0; i <car_count; i++){

    ptr = strtok(str[i],",");  
    word_count=0;
    
    while(ptr != NULL){
      word[i][word_count] = (char*)malloc(sizeof(char)*WORD_SIZE);
      del =  strchr(ptr, '\r');
      if(del)
    	  *del = 0;
      del = strchr(ptr, '\n');
      if(del)
    	  *del =0;
      
      strcpy(word[i][word_count],ptr);
      ++word_count;
      ptr = strtok(NULL,",");// NULL이다!
		}
	}
	free_arr(str,car_count);

  // Car *car[count];
  // car 에 삽입하기
  for(int i=0; i< car_count ; i++){
  	
      //car[i] = (Car*)malloc(sizeof(Car)*count);
      strcpy(car[i].name, word[i][name]);    
      car[i].retail_price = atoi(word[i][RP]);
      car[i].engine_size = atof(word[i][ES]);
      car[i].dealer_cost = atoi(word[i][DC]);
      car[i].weight = atoi(word[i][weight]);
      car[i].width = atoi(word[i][width]);
      free_arr(word[i],word_count); 
   }
  return car_count;
}
