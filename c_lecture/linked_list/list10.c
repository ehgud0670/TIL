# include <stdio.h>
# include <stdlib.h>

# define NUM 5
// 또 다른 함수의 호출

typedef struct user{
  char name[32];
  int age;

}User;

typedef struct node{
	void* data;
  struct node *prev;
  struct node *next;
} Node;


Node head = { 0 , &head , &head };  

void insert_node(Node *prev, Node *next, Node *new){

  new -> prev = prev;
  new -> next = next;
  next -> prev = new;
  prev -> next = new;
}


void insert_rear(Node *node, Node *new ){
 
  insert_node(node, node ->next,new);
}

void insert_front(Node *node, Node *new){ 
  
  insert_node(node->prev,node , new);
}

void print_list(Node *head){

  Node *current = head->next;
  
  while(current!=head){ 
  	User *user = (User*)(current -> data); 
    printf("<%s , %d> \n", user->name, user->age );
    current = current -> next;
	}

}

int main(){

 int i;
 User user[NUM] = {{"Kim",24},{"Gyu",25},{"Ho",27},{"Park",20},{"Star",17}};
 Node node[NUM];

 for(i=0;i<NUM;i++){
 	  node[i].data = user+i;
  	insert_rear(&head, node+i); //node의 인자 값 전달 방식이 call by reference 이므로 
 	 // insert_front(&head2, node2+i, data); //insert_rear 와 insert_front의 node 전송을 서로 다른 변수로 하자.
  }

  print_list(&head);
  return 0;
}
