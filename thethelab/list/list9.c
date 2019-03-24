# include <stdio.h>
# include <stdlib.h>
# define list_entry(ptr, type, member) \
     (type*)((char*)ptr - (size_t)&((type*)0)->member)

struct node{
  struct node *prev;
  struct node *next;
};

typedef struct user{
  char name[32];
  int age;
  struct node links;
}User;


struct node head = {&head,&head};

void print_list(struct node *head){

  struct node *current = head->next;
  printf("<head>\n");

  while(current != head){
  	User *user = list_entry(current, User, links); 
  	printf("-<%s, %d>", user -> name, user->age);  
  
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

User user[3] = {{"Tom",24},{"Bob",27},{"Alex",50}};

int main(){
  int i;

  for(i=0;i<3;i++){
   
    add_front(&head, &(user[i].links));
	}
  print_list(&head);


  return 0;
}
