#include <stdio.h>
# define VERTEX_NUM 4;

int graph[4][4]; // init with zero


void addEdge(int vertexA, int vertexB){

	graph[vertexA][vertexB]  = 1;
	graph[vertexB][vertexA]  = 1;

}

void printMatrix(){

	int i;
	int j;

	for(i=0; i<VERTEX_NUM  i++){
		for(j=0; j<VERTEX_NUM j++){
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}

}
void showAdjacentVertex(int vertex){
	int check = 0;

	printf("{");
	for(int i=0; i<VERTEX_NUM i++){
		if(i == vertex){
			continue;
		}
		if(graph[vertex][i] == 1){
			if(check == 0){
				check = 1;
				printf("%d,", i);
			} else{
				printf(",%d", i);
			}
		}
	}
	printf("}\n");


}

int main(){


	addEdge(0,1);  // 0 -> 1 , 1 -> 0
	addEdge(0,2);  // 0 -> 2 , 2 -> 0


	printMatrix();
  showAdjacentVertex(0);

	return 0;
}
