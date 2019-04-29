//Breadth First Search (BFS)

#include <iostream>
#include <list>

using namespace std;

class Graph {

	//number of verticies
	int V;

	//pointer to the array containing adjacency list
	list<int> *adjacency;

public:
	Graph(int V);
	void addEdge(int v, int W);
	void BFS(int s);
};

Graph::Graph(int V) {
	this->V = V;
	//update list to be the size of V
	adjacency = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	//adding w to v's list.
	adjacency[v].push_back(w);
}

void Graph::BFS(int s) {
	//to start off, mark all verticies as not visited
	//to do this, have an array of length V to represent if each index is discoved
	//false = no, true = yes
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	//creating a queue for BFS
	list<int> queue;
	//mark the current node (s) as visited
	visited[s] = true;
	queue.push_back(s);


	list<int>::iterator i;

	while (!queue.empty()) {
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); i++) {
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}

int main() {
	Graph graph(4);
	graph.addEdge(0, 1);
	graph.addEdge(0, 3);
	graph.addEdge(1, 2);
	graph.addEdge(2, 0);


	graph.BFS(2);

	return 0;
}