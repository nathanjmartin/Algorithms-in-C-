//Depth First Search (DFS)
//very similar to BFS (take a look at that as well)

#include <iostream>
#include <list>

using namespace std;

class Graph {
	//Number of verticies
	int V;

	//Pointer to the array contianing adjacency list
	list<int> *adjacency;

	//recursive function for DFS
	void DFSUtility(int v, bool visited[]);
public:
	Graph(int V); //constructor
	void addEdge(int v, int w);
	void DFS(int v);
};

Graph::Graph(int V) {
	this->V = V;
	adjacency = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adjacency[v].push_back(w);
}

void Graph::DFSUtility(int v, bool visited[]) {
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adjacency[v].begin(); i != adjacency[v].end(); i++) {
		if (!visited[*i])
			DFSUtility(*i, visited);
	}
}

void Graph::DFS(int v) {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	DFSUtility(v, visited);
}

//main
int main() {
	Graph graph(4);
	graph.addEdge(0, 1);
	graph.addEdge(0, 3);
	graph.addEdge(1, 2);
	graph.addEdge(2, 0);


	graph.DFS(2);

	return 0;
}