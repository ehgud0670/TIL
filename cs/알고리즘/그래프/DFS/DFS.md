## DFS(Depth - First - Search) : 깊이 우선 탐색


* 아래 그림처럼 깊이를 우선으로 탐색하는 방법을 DFS라고 한다. 아래의 그림을 예시로 들면, 우선 노드 0을 탐색하고 이후 0과 연결된 노드 1을 탐색한다. 이후 1과 연결된 노드 3을 탐색하고 노드 3과 연결된 또 다른 노드가 없으므로 노드 1로 backtracking해서 연결된 노드 4를 탐색한다. 이후 노드 4와 연결된 또 다른 노드가 없으므로 노드 1로 backtracking하고 노드 1도 연결된 다른 노드(방문하지 않은 노드)가 없으므로 0으로 backtracking한다. 이후 0과 연결된 노드 중 방문하지 않은 노드 2 를 탐색하고 이후 노드 2와 연결된 노드 5를 탐색, 노드 5가 연결된 또 다른 노드가 없으므로 노드 2로 backtracking, 이후 2와 연결된 노드 6을 탐색한다.<br> 위와 같은 방식으로 탐색하면, 방문 순서는 0 -> 1 -> 3 -> 4 -> 2 -> 5 -> 6 이 된다. 위와 같은 방식이 BFS이고 깊이 우선 탐색이다. 왜냐하면 아래로 내려갈 수 있을 때까지 내려간다음, 더이상 내려갈 수 없으면 위로 되돌아와 다시 내려가는 방식으로 **깊이 내려갈때까지 내려가기 때문이다.(=연결된 곳이 있을 때까지 깊이 탐색하기 때문이다)** 


<br><br><br>
![dfs](https://user-images.githubusercontent.com/38216027/60230924-8dbc6900-98d2-11e9-995a-a5dea1da5fd4.png)




## DFS 방법 1 : 재귀 함수 이용

```c
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

/*---------- graph related ----------*/
void add_next(int v1, int v2){

  struct Node *new = (struct Node*)malloc(sizeof(struct Node));
  new -> vertex_num = v2;
  new -> next = NULL;

  struct Node *cur = graph[v1]; 
  if(cur == NULL){
    graph[v1] = new;
  } else {
   
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

void aDFS(int v){

  visited[v] = TRUE;
  printf("visited vertex: %d \n", v);
  struct Node *cur = graph[v];

  while(cur){
    int vertex_num = cur -> vertex_num; 
    if(visited[vertex_num] == FALSE){
      aDFS(vertex_num);
    }
    cur = cur -> next;
  }
}

void doDFS(){
  int i;
  for(i=0; i<VERTEX_TOTAL_NUM;i++){
    if(visited[i] == FALSE){
      aDFS(i);
    }
  }
}



int main(){

  addEdge(0,4,TRUE);
  addEd**ge(0,5,TRUE);
  addEdge(0,6,TRUE);
  addEdge(4,1,TRUE);
  addEdge(5,2,TRUE);
  addEdge(6,3,TRUE);

  printLists();
  showAdjacentVertex(0);
  
  doDFS();  
  return 0;
}
// 실행 결과
// vertex 0: 4 5 6 
// vertex 1: 4 
// vertex 2: 5 
// vertex 3: 6 
// vertex 4: 0 1 
// vertex 5: 0 2 
// vertex 6: 0 3 

// vertex 0: 4 5 6 

// visited vertex: 0 
// visited vertex: 4 
// visited vertex: 1 
// visited vertex: 5 
// visited vertex: 2 
// visited vertex: 6 
// visited vertex: 3
```
### => (0) -> (4) -> (1) -> (5) -> (2) -> (6) -> (3)
### => doDFS()와  aDFS()에 초점을 맞춰서 얘기해보자. doBFS()는 for문을 이용해 노드번호를 오름차순으로 dfs방식으로 탐색한다. 만약 탐색할 노드가 방문하지 않았다면(visited[i] == FALSE ) **aDFS(탐색할 노드 번호 i)을 호출 한다.**
### => aDFS()는 재귀함수로 우선 매개값의 노드를 방문 기록한다.(visited[v] = TRUE) 이후 매개값의 노드와 연결된 노드를 대상으로 방문 기록을 체크하고 방문하지 않았다면 **다시 aDFS(연결된 노드 번호,j)를 호출한다. 이후 노드 j를 방문 기록하고, 또 j와 연결된 노드를 대상으로 aDFS()를 호출하는 식으로 계속 함수를 호출한다.** 이렇게 연결된 노드들 중에 방문하지 않은 노드를 기준으로 **계속 재귀적으로 함수가 호출되며 깊이 우선(DFS)으로 노드를 방문됨을 알 수 있다.** 



<br><br><br><br>

## DFS 방법 2 : 자료구조인 스택 사용

```c
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
  } else {

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
// 실행 결과 
// vertex 0: 4 5 6 
// vertex 1: 4 
// vertex 2: 5 
// vertex 3: 6 
// vertex 4: 0 1 
// vertex 5: 0 2 
// vertex 6: 0 3 

// vertex 0: 4 5 6 

// visited vertex : 0 
// visited vertex : 4 
// visited vertex : 1 
// visited vertex : 5 
// visited vertex : 2 
// visited vertex : 6 
// visited vertex : 3 
```
### => (0) -> (4) -> (1) -> (5) -> (2) -> (6) -> (3)
### => doDFS()와 findNextVertex()에 초점을 맞춰서 얘기해보자. 우선 맨 처음 방문할 노드를 방문 기록하고(visited[vertex_num] = TRUE;), push하여 스택에 넣는다. 이후 findNextVertex()함수를 호출하여 이 노드의 연결된 노드 중 방문하지 않은 노드가 있는 지 확인한다. 있다면 다시 doDFS()에서 그 노드를 push하여 스택에 집어넣고 또 연결된 노드가 있는 지 반복 확인한다. 만약 없다면 pop하여 노드를 제거한다. 이러한 방식으로 스택이 빌때 까지 수행하면 깊이우선탐색(DFS)이 이루어진다. 




<br><br><br>

> ## 체크해야 될 점!
*  ## DFS : 자료구조로 스택을 사용. (last - in 된  노드를 필요로 하므로) 
*  ## BFS : 자료구조로 큐를 사용. (first - in 된 노드를 필요로 하므로)