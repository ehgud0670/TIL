# include <stdio.h>
# include <stdlib.h>

struct node{

  int data;
  struct node *prev;
  struct node *next;
};

struct node head1 = { 0, &head1,&head1};
struct node head2 = { 0, &head2,&head2};

void print_list(struct node *head){

  struct node *current = head->next;
  printf("<head>\n");

  while(current != head){
  	printf("-<%d>", current -> data);  
  
    current = current -> next;
	}
  printf("\n");

}

void add_front(struct node *head,int data){
 
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp -> data = data;
  
  temp -> prev = head -> prev;
  temp -> next = head;
  head -> prev -> next = temp;
  head -> prev = temp;
}

void add_next(struct node *head,int data){
 
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp -> data = data;
  
  temp -> next = head -> next;
  temp -> prev = head;
  head -> next -> prev = temp;
  head -> next = temp;
}


int main(){
  int arr[3] = {1,2,3};
  int i;

  for(i=0;i<3;i++){
    add_front(&head1,arr[i]);
    add_next(&head2,arr[i]);
	}
  print_list(&head1);
  print_list(&head2);


  return 0;
}
