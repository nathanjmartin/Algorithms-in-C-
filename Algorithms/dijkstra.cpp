//C++ implementation of dijkstra
#include <iostream>
#include <limits.h>

#define V 9
using namespace std;

//utility function to find the minimum distance
int minimumDistance(int distance[], bool shortestPathSet[]) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++) 
		if (shortestPathSet[v] == false && distance[v] <= min)
			min = distance[v], min_index = v;
	return min_index;
}

//utility function to print the distance array
void printSolution(int distance[], int n) {
	for (int i = 0; i < V; i++) {
		cout << distance[i] << " ";
	}
}

//dijkstra's algorithm
void dijkstra(int graph[V][V], int source) {
	int distance[V];
	bool shortestPathSet[V];

	for (int i = 0; i < V; i++)
		distance[i] = INT_MAX, shortestPathSet[i] = false;

	distance[source] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = minimumDistance(distance, shortestPathSet);
		shortestPathSet[u] = true;

		for (int v = 0; v < V; v++)
			if (!shortestPathSet[v] && graph[u][v] && distance[u] != INT_MAX
				&& distance[u] + graph[u][v] < distance[v])
				distance[v] = distance[u] + graph[u][v];
	}

	printSolution(distance, V);
}

//main function with a common graph example
int main() {
	int graph[V][V] = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
					  {4, 0, 8, 0, 0, 0, 0, 11, 0},
					  {0, 8, 0, 7, 0, 4, 0, 0, 2},
					  {0, 0, 7, 0, 9, 14, 0, 0, 0},
					  {0, 0, 0, 9, 0, 10, 0, 0, 0},
					  {0, 0, 4, 14, 10, 0, 2, 0, 0},
					  {0, 0, 0, 0, 0, 2, 0, 1, 6},
					  {8, 11, 0, 0, 0, 0, 1, 0, 7},
					  {0, 0, 2, 0, 0, 0, 6, 7, 0}
	};

	dijkstra(graph, 0);

	return 0;
}