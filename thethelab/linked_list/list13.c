# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>  //offsetof(type,member)

# define NUM 5
// 또 다른 함수의 호출
# define list_entry(ptr,type,member) \
    (type*)((char*)ptr - (unsigned long)(&(((type*)0)->member)))

typedef struct node{
  struct node *next;
} Node;

typedef struct user{
  char name[32];
  int age;
  Node links;
}User;


Node head = { &head };  

void add_next(Node *node, Node *new ){

   new -> next = node -> next; // 조심!
   node -> next = new;
}
void del_next(Node *node){
   
   Node *delNode = node ->next;
   Node *delNodeNext = delNode -> next;
   
   node -> next = delNodeNext;
   delNode -> next = NULL;
}
  
void print_list(Node *head){
    
  Node *current = head->next;
  system("clear");
  printf("<head>");
  while(current!=head){

  	//printf("%ld" ,offsetof(User,links));
  	User *user = list_entry(current, User,links); 
    printf("-<%s , %d>", user->name, user->age );
    current = current -> next;
	
	}
  getchar();
}

int main(){

 int i;
 User user[NUM] = {{"Kim",24},{"Gyu",25},{"Ho",27},{"Park",20},{"Star",17}};

 for(i=0;i<NUM;i++){
  	add_next(&head, &(user[i].links)); //node의 인자 값 전달 방식이 call by reference 이므로 
 	 // insert_front(&head2, node2+i, data); //insert_rear 와 insert_front의 node 전송을 서로 다른 변수로 하자.
 	 print_list(&head);
  }
 for(i=0;i<NUM;i++){
  	del_next(&head); //node의 인자 값 전달 방식이 call by reference 이므로 
 	 // insert_front(&head2, node2+i, data); //insert_rear 와 insert_front의 node 전송을 서로 다른 변수로 하자.
 	 print_list(&head);
  }

  return 0;
}
