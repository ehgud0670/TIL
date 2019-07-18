# include <stdio.h>
# include <stdlib.h>

# define VERTEX_TOTAL_NUM 9  
# define TRUE 1
# define FALSE 0

void printVisited();
void printQueue();

struct Node {

  int vertex_num;
  struct Node *next;

};

struct Queue{

  struct Node *arr[VERTEX_TOTAL_NUM];
  
};

struct Node *graph[VERTEX_TOTAL_NUM];

struct Queue queue;
int size = VERTEX_TOTAL_NUM;
int in_index = 0;
int out_index = 0;

// Queue related

void initQueue(){
   int i;
   for(i= size == VERTEX_TOTAL_NUM? 0 : size/2 ; i<size; i++){
     queue.arr[i] = NULL;
	 }
}

void enqueue(struct Node *node){
  if(in_index == size){
    size = 2*size;
    initQueue();

    queue.arr[in_index++] = node;
    return ;
	} 

  queue.arr[in_index++] = node;
  return ;
}

struct Node* (dequeue()){
  if(out_index == in_index){
    printf("no data\n");
    return NULL;
	}
	struct Node *node = queue.arr[out_index];
	queue.arr[out_index++] = NULL;

  return node;
}

struct Node* (peek()){
  if(out_index == in_index){
    printf("no data\n");
    return NULL;
	}
  
  return queue.arr[out_index];
}

// return 1 if the queue is empty
// 				0 otherwise
int isQueueEmpty(){
  printQueue();  
  int count = 0;
  int i;
 
  for(i=0; i<size;i++){
    struct Node *node = queue.arr[i];
    if(!node){
      continue;
		}
		count++;
	}

	return count == 0 ? TRUE : FALSE;

}

void printQueue(){
   
   int i;
   
   printf("Order : first - in \n");
   
   for(i=0; i<size;i++){
     struct Node *node = queue.arr[i];
     if(node == NULL){
       continue;
		 }
	   printf("%d ", node -> vertex_num);
	
	 }
	 printf("\n");
}


// Graph related
void initGraph(){
  int i;
  for(i=0; i<VERTEX_TOTAL_NUM;i++){

    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	  node -> vertex_num = i;
	  node -> next = NULL;
	  
	  graph[i] = node;
	}

}


void printLists(){
  int i;
  for(i=0; i<VERTEX_TOTAL_NUM; i++){
  	 printf("Node %d: ", i);
     struct Node *cur = graph[i] -> next;
     
     while(cur){
       int vertex_num = cur -> vertex_num;
       printf("%d ", vertex_num);

       cur = cur -> next;
		 }
		 printf("\n");
	}
	printf("\n");
}

void showAdjacentVertex(int vertex_num){
  
  struct Node *cur = graph[vertex_num] -> next;
  printf("Node %d: ", vertex_num);
  while(cur){

    printf("%d ", cur -> vertex_num);
    cur = cur-> next;
	}
  printf("\n");
}


void add_next(int v1 , int v2){
  
  struct Node *cur = graph[v1] -> next;
  struct Node *new = (struct Node*)malloc(sizeof(struct Node));
  new -> vertex_num = v2;
  new -> next = NULL;

  if(!cur){
    graph[v1] -> next = new;
    return;
	}

  while(1){

    if(!(cur -> next)){
      cur -> next = new;
      break;
		}

    cur = cur -> next;
	}
}

void addEdge(int v1, int v2, int reverse){

   add_next(v1, v2);
   if(reverse == TRUE){
     add_next(v2, v1);
	 }
}

int visited[VERTEX_TOTAL_NUM];
int count=0;

void doBFS(int vertex_num){
  
  enqueue(graph[vertex_num]);

  while(isQueueEmpty() == FALSE){
    struct Node *cur = peek() -> next;

    while(cur){
      int check = FALSE;
      int temp_num = cur -> vertex_num;
      
      int i;     
      for(i=out_index;i<in_index;i++){
        if(temp_num == queue.arr[i]->vertex_num){
           check = TRUE;
           break;
				}
			}
			for(i=0;i<count;i++){
        if(temp_num == visited[i]){
           check = TRUE;
           break;
				}
			}

			if(check == FALSE){
        enqueue(graph[temp_num]);
			}

      cur = cur -> next;
		}
    
    int num = dequeue()-> vertex_num;
    visited[count++] = num;
	}

}



void printVisited(){
  int i;
  printf("visited: ");
  for(i=0;i<count;i++){
    printf("%d ", visited[i]);
	}
	printf("\n");
}

int main(){

  initGraph();  
  
	addEdge(0,1,TRUE);
	addEdge(0,3,TRUE);
	addEdge(0,7,TRUE);
	addEdge(1,2,TRUE);
	addEdge(1,4,TRUE);
	addEdge(3,4,TRUE);
	addEdge(3,6,TRUE);
	addEdge(7,6,TRUE);
	addEdge(7,8,TRUE);
	addEdge(2,5,TRUE);
	addEdge(4,5,TRUE);

  printLists();
  
  initQueue();
  doBFS(0);
  printVisited();
  return 0;
}
