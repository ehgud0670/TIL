# include <stdio.h>
# include <stdlib.h>

struct node{

  int data;
  struct node *next;
};

struct node head = { 0, &head};

void print_list(struct node *head){

  struct node *current = head->next;
  printf("<head>\n");

  while(current != head){
  	printf("-<%d>", current -> data);  
  
    current = current -> next;
	}
  printf("\n");

}

void add_next(struct node *head,int data){
 
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp -> data = data;
  
  temp -> next = head -> next;
  head -> next = temp;

}


int main(){
  int arr[3] = {1,2,3};
  int i;

  for(i=0;i<3;i++)
    add_next(&head,arr[i]);
  print_list(&head);

  return 0;
}
