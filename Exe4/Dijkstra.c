// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
#include "Dijkstra.h"
// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[],int size){
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < size; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int **graph,int size, int src){
	int * dist=(int *)malloc(size*sizeof(int)); // The output array. dist[i] will hold the
	// shortest
	// distance from src to i
    if(dist==NULL) printf("Memory allocation failed\n");

	bool * sptSet=(bool*)malloc(size*sizeof(bool)); // sptSet[i] will be true if vertex i is
	// included in shortest
	// path tree or shortest distance from src to i is
	// finalized
    if(sptSet==NULL){  
        free(dist);
        printf("Memory allocation failed\n");
    }
    

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < size; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < size - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, sptSet,size);
        
		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < size; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}


	// print the constructed distance array
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < size; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
    free(dist);
    free(sptSet);
}

int freeMatrix(int** matrix){
    for(int i=0;i<v;i++){
        free(matrix[i]);
    }
    free(matrix);
}

int main(void){

    int v;
    printf("Enter number of Vertices:\n");
    int res = scanf("%d",&v);
    if(!res) {
        perror("invalid argument: not a number");
        return 1;
    }
    if (v<=0){
        perror("not matrix with size 0 or negative");
        return 1;
    }

    int** matrix = (int**)malloc(sizeof(int*)*v);
    if(!matrix){
        perror("malloc");
        return 1;
    }

    for(int i=0;i<v;i++){
        matrix[i] = (int*) malloc(sizeof(int)*v);
        if(!matrix[i]){
            freeMatrix(matrix);
            return 1;
        }
        printf("Enter Row %d:\n",i);
        int j = 0;
        char c;
        int w;
        while (1)
        {
            int res1 = scanf("%d",&w);
            if(!res1){
                perror("invalid argument: not a number");
                freeMatrix(matrix);
                return 1;
            }
            scanf("%c",&c);
            if(j >= v){
                perror("too much arguments provided in row");
                freeMatrix(matrix);
                return 1;
            }

            if(w < 0){
                perror("provided invalid argument: negative number or not a number");
                freeMatrix(matrix);
                return 1;
            }
            if(i==j && w != 0){
                perror("provided invalid argument: no edge from v to v");
                freeMatrix(matrix);
                return 1;
            }
            matrix[i][j] = w;
            j++;

            if(c!=' ' && c!='\n'){
                perror("not space or end line");
                freeMatrix(matrix);
                return 1;
            }

            if(c == '\n'){ break;}
        }
        if(j < v){
            perror("not enough arguments provided in row");
            freeMatrix(matrix);
            return 1;
        }
    }

    printf("the matrix\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    dijkstra(matrix,v,0);

    return 0;
}
