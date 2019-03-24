# include <stdio.h>
# include <stdlib.h>

# define NUM 5
// 또 다른 함수의 호출

typedef struct node{

  struct node *prev;
  struct node *next;

}Node;

typedef struct user{
  
  char name[32];
  int age;
  Node link;

}User;

Node head = {&head , &head };  

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

// User *user =(User*)((char*)current- &((User*)0 -> link));


void print_list(Node *head){

  Node *current = head->next;
  
  while(current!=head){ 
    
    User *user =(User*)((char*)current -(char*)&(((User*)0) -> link));
    //User *user =(User*)((char*)current -(sizeof(User)-sizeof(Node))); 
    printf("%s %d\n", user -> name, user -> age );
    current = current -> next;
	}
	printf("\n");

}

User user[NUM]={{"Kim",27},{"Hyun",37},{"Ho",10},{"Jun",50},{"Gyu",17}};


int main(){

  int i;
  for(i=0;i<5;i++){
  	insert_rear(&head, &user[i].link); //node의 인자 값 전달 방식이 call by reference 이므로 
 	 // insert_front(&head2, node2+i, data); //insert_rear 와 insert_front의 node 전송을 서로 다른 변수로 하자.
  }
  print_list(&head);
  
  
  return 0;
}
