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


int main(){
    int **graph; // Pointer to pointer for 2D array
    int size;
    printf("Enter the size of the matrix:\n");
    scanf("%d",&size);
    // Allocate memory for the graph matrix
    graph = (int **)malloc(size* sizeof(int *));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        graph[i] = (int *)malloc(size * sizeof(int));
        if (graph[i] == NULL) {
            printf("Memory allocation failed\n");
            // Free memory for previously allocated rows
            for (int j = 0; j < i; j++) {
                free(graph[j]);
            }
            // Free memory for graph pointer array
            free(graph);
            return 1;
        }
    }
    for (int i = 0; i < size; i++) {
        printf("Enter row %d: ", i + 1);

        // Read the row of the graph matrix
        for (int j = 0; j < size; j++) {
            if (scanf("%d", &graph[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                // Free memory before returning
                for (int k = 0; k < size; k++) {
                    free(graph[k]);
                }
                free(graph);
                return 1;
            }
            if (graph[i][j] < 0) {
                printf("Negative numbers are not allowed.\n");
                // Free memory before returning
                for (int k = 0; k < size; k++) {
                    free(graph[k]);
                }
                free(graph);
                return 1;
            }
            if (i != j && graph[i][j] != graph[j][i]) {
                printf("Graph is not directed, but matrix is not symmetric.\n");
                // Free memory before returning
                for (int k = 0; k < size; k++) {
                    free(graph[k]);
                }
                free(graph);
                return 1;
            }
        }

        // Check if too many numbers were entered
        int c;
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);

        if (c == EOF) {
            printf("Not enough numbers entered.\n");
            // Free memory before returning
            for (int j = 0; j <= i; j++) {
                free(graph[j]);
            }
            free(graph);
            return 1;
        }
    }

    // Function call
    dijkstra(graph, size,0);

    // Free memory
    for (int i = 0; i < size; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

