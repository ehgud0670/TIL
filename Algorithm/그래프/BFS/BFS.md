## BFS (Breadth-First-Search). 너비 우선 탐색

* BFS는 너비 우선 탐색으로 탐색한 노드와 연결된 모든 노드들을 우선 탐색하는 방식이다. 아래 그림을 예로 들면, 노드 A부터 탐색을 한다 했을 때 , 노드 A를 탐색하고 이후 노드 A와 연결된 노드인 B,C,D를 우선 탐색하고 이후 B와 연결된 E,F를 탐색, 이후 C와 연결된 G를 탐색한다. 그림에서 보이는 것처럼 BFS는 한 행씩 점층적으로 탐색함을 알 수 있다.

<br>
<br>

![BFS](https://user-images.githubusercontent.com/38216027/60227797-978e9e00-98cb-11e9-8566-a0062ed7ec73.png)

<br><br><br>
위의 그림과 같이 동작하는 BFS 알고리즘을 c로 표현하면 다음과 같다. 

```c
#include <stdio.h>
#include <stdlib.h>

#define VERTEX_NUM 7
#define QUEUE_SIZE 6 
#define TRUE 1
#define FALSE 0

int isQueueEmpty();
int isQueueFull();

struct Node {
  int v;
  struct Node *next;
};

struct Node *graph[VERTEX_NUM];

/* ----방문 기록을 저장하는 배열---- */
// if visited, visited[i] = 1
//  otherwise, visited[i] = 0    
int visited[VERTEX_NUM];

// related queue
int queue[QUEUE_SIZE];

int front = 0;
int rear = 0;

void enqueue(int v){

   if(isQueueFull() == TRUE){
      printf("----queue is full----\n");
	  return;
   }
   rear = (rear + 1) % QUEUE_SIZE;
   queue[rear] = v;
}

int dequeue(){

  if(isQueueEmpty() == TRUE){
    printf("----queue is empty----\n");
	  return -1;
  }
  front = (front + 1) % QUEUE_SIZE;
  int v = queue[front];
  queue[front] == -1;
  
  return v;
} 

int isQueueEmpty(){

  return rear == front ? TRUE : FALSE;

}

int isQueueFull(){

  return (rear + 1) % QUEUE_SIZE == front ? TRUE : FALSE;   

}

void printQueue(){
  int i;
  // rear의 인덱스가 front의 인덱스보다 작을 수 있으므로(원형 큐라서)
  // 따라서 그냥 전체를 검사하고 -1인 경우를 제외한다. 
  for(i = 0; i < QUEUE_SIZE; i++){
    int v = queue[i];
      if(v != -1){
        printf("%d ",v);
      }
  }
  printf("\n");
}

// related graph

void add_next(int v1,int v2){

  struct Node *new = (struct Node*)malloc(sizeof(struct Node));
  new -> v = v2;
  new -> next = NULL;

  struct Node *cur = graph[v1];

  if(!cur){
    graph[v1] = new;  
  } else {

    while(1){
      if(!cur -> next){
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
  for(i=0; i<VERTEX_NUM; i++){
    printf("vertex %d :", i);
    struct Node *cur = graph[i];
    while(cur){
      printf("%d ", cur -> v);
      cur = cur -> next;
    }
    printf("\n");
  }
  printf("\n");
}

void showAdjacentVertex(int v){

  printf("vertex %d :", v);

  struct Node *cur = graph[v];
  while(cur){
    printf("%d ", cur -> v);
    cur = cur -> next;
  }
  printf("\n");

}

void enqueueAdjacentVertex(int vertex_num){

  struct Node *cur = graph[vertex_num];

  while(cur){
    int v = cur -> v;
    int i;
    // check v is already visited 
    if(visited[v] == FALSE){
      // check v is already in the queue 
      int equalCheck = FALSE;
      for(i=0;i<QUEUE_SIZE;i++){
        if(v == queue[i]){
          equalCheck = TRUE;
          break;
        }
      }
      if(equalCheck == FALSE){
        enqueue(v);
      }
    }

    cur = cur -> next;
  
  }

}

void doBFS(int v){

  enqueue(v);

  while(isQueueEmpty() == FALSE){

    int vertex_num = dequeue();
      visited[vertex_num] = TRUE;
      printf("visited vertex: %d \n",vertex_num);

      enqueueAdjacentVertex(vertex_num);
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
  doBFS(0); 

  return 0;
}
// 실행 결과
// vertex 0 :4 5 6 
// vertex 1 :4 
// vertex 2 :5 
// vertex 3 :6 
// vertex 4 :0 1 
// vertex 5 :0 2 
// vertex 6 :0 3 

// visited vertex: 0 
// visited vertex: 4 
// visited vertex: 5 
// visited vertex: 6 
// visited vertex: 1 
// visited vertex: 2 
// visited vertex: 3

```

## => 위의 코드에서 void doBFS(int v)라는 함수만 살펴보자. 우선 위의 코드처럼 **BFS를 하려면 자료구조로 큐를 사용해야 한다.** 
### => 맨 처음 탐색해야 할 노드를 **enqueue()** 하여 집어넣는다. 그리고 **dequeue()** 하여 노드를 반환하고(맨 처음에는 집어넣은 노드가 반환되겠지) 반환된 노드를 방문 기록한다. 이후 반환된 노드와 연결된 노드 중에 방문하지 하지 않은 노드들을 모두 enqueue()한다. 이후 다시 dequeue()하여 한 노드를 반환하고 그 노드를 방문 기록하고, 이 노드와 연결된 노드중에 또 방문 되지않은 노드들은 enqueue() 하는 것을 **큐가 비워질때까지 반복**하면 BFS의 순서대로 노드가 방문됨을 알 수 있다.
### => 여기서 주의할 점은 방문하지 않았다고 바로 enqueue()을 하는 것이 아니라 큐 안에 이미 같은 번호의 노드가 들어가 있지 않은지 확인하고 enqueue()을 하자. **큐안에 있는 모든 노드들은 어차피 dequeue()되어 방문 기록될 것이기 때문에 큐안에 이미 같은 번호의 노드가 들어가 있다면 넣지 않아도 된다.**