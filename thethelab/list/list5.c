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


void __add_node(struct node *prev , struct node *next, struct node *new){

  new -> next = next;
  new -> prev = prev;
  prev -> next = new;
  next -> prev = new;

}


void add_front(struct node *head, struct node *new){
  
    __add_node(head->prev, head, new);
}

void add_next(struct node *head, struct node *new){
 
    __add_node(head, head->next , new);
}


int main(){
  int arr[3] = {10,20,30};
  int i;
  struct node node1[3];
  struct node node2[3];

  for(i=0;i<3;i++){
  	node1[i].data = arr[i];
  	node2[i].data = arr[i];
   
    add_front( &head1, node1+i);
    add_next( &head2, node2+i);
	}
  print_list(&head1);
  print_list(&head2);


  return 0;
}
