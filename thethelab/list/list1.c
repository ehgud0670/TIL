# include <stdio.h>
# include <stdlib.h>

struct node{

  int data;
  struct node *next;
};

struct node *head = NULL;

void print_list(){

  struct node *current = head;
  printf("<head>\n");

  while(current != NULL){
  	printf("-<%d>", current -> data);  
  
    current = current -> next;
	}
  printf("\n");

}

void add_next(int data){
 
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp -> data = data;
  

  if(head == NULL){
    temp -> next = NULL;
	}
  else{
    temp -> next = head; 
	}
  head = temp;

}


int main(){
  int arr[3] = {1,2,3};
  int i;

  for(i=0;i<3;i++)
    add_next(arr[i]);
  print_list();

  return 0;
}
