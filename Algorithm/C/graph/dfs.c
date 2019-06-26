#include <stdio.h>
#include <stdlib.h>

#define VERTEX_TOTAL_NUM 7 
#define TRUE 1
#define FALSE 0

struct Node{
  
  int vertex_num;
  struct Node *next;
};


struct Node *graph[VERTEX_TOTAL_NUM]; // init with null

/*---------- vertex 방문여부 표시 배열----------*/
// if visited[i] == 1, visited
//                  0, otherwise
int visited[VERTEX_TOTAL_NUM]={0,};

/*---------- stack related ----------*/
int stack[VERTEX_TOTAL_NUM]= {-1,};
int top = -1;

void push(int vertex_num){
  
  if(top == VERTEX_TOTAL_NUM -1){
    printf("-------stack is full------ \n");
    return;
	}
  stack[++top] = vertex_num;

}

int pop(){
  if(top == -1){
    printf("------stack is empty------ \n");
    return -1;
	}
  int vertex_num = stack[top];
  stack[top--] = -1;

  return vertex_num;
}

int peek(){
  if(top == -1){
    printf("stack is empty \n");
    return -1;
	}
  int vertex_num = stack[top];
  return vertex_num;
}

int isStackEmpty(){
  // top 덕분에 for문을 쓰지 않아도 된다.  
	return top == -1? TRUE : FALSE;

}

/*---------- graph related ----------*/
void add_next(int v1, int v2){

  struct Node *new = (struct Node*)malloc(sizeof(struct Node));
  new -> vertex_num = v2;
  new -> next = NULL;

  struct Node *cur = graph[v1]; 
  if(cur == NULL){
     graph[v1] = new;
	} else{

		while(1){
      if(cur -> next == NULL){
        cur -> next = new;
        break;
			}
      cur = cur -> next;
		}
	}
}

void addEdge(int v1, int v2, int reverse){

  add_next(v1,v2);
  if(reverse == TRUE){
    add_next(v2,v1);
	}
}

void printLists(){

  int i;
  for(i=0; i<VERTEX_TOTAL_NUM;i++){
    printf("vertex %d: ",i);
    struct Node *cur = graph[i];
    while(cur){
      int num = cur -> vertex_num;
      printf("%d ", num);
      cur = cur -> next;
		}
		printf("\n");
	}
	printf("\n");
}

void showAdjacentVertex(int vertex_num){

     
    printf("vertex %d: ",vertex_num);
    struct Node *cur = graph[vertex_num];
    while(cur){
      int num = cur -> vertex_num;
      printf("%d ", num);
      cur = cur -> next;
		}
		printf("\n");
}


int findNextVertex(int vertex_num){
 
  struct Node *cur = graph[vertex_num];
  
  while(cur){
    int num = cur -> vertex_num;

    if(visited[num] == TRUE){
      cur = cur -> next;
      continue;		
		}

    return num;
		
	}
    
  return -1;
}
void doDFS(int vertex_num){
  
  visited[vertex_num] = TRUE;
  printf("visited vertex : %d \n",vertex_num);
  push(vertex_num); 

  while(isStackEmpty() == FALSE){
    int next_vertex = -1;
    next_vertex = findNextVertex(peek());
    
    if(next_vertex == -1){
      pop();
		} else {
      visited[next_vertex] = TRUE;
      printf("visited vertex : %d \n",next_vertex);
      push(next_vertex);
		}
	}
}



int main(){

	addEdge(0,4,TRUE);
	addEdge(0,5,TRUE);
	addEdge(0,6,TRUE);
	addEdge(4,1,TRUE);
	addEdge(5,2,TRUE);
	addEdge(6,3,TRUE);

  printLists();
  showAdjacentVertex(0);
  
  doDFS(0);
  
  return 0;
}
