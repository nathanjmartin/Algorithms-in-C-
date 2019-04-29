/* Kruskal's Algorithm

Kruskal's Algorithm's goal is to find the Minimum Spanning Tree (MST) within a spanning tree of
a conntected, undirected graph.

*/

/*
Pseudocode

For each vertex v belonging in the graph
		make-set(v)

for each (u, v) in G.E ordered by weight(u, v), increasing:
	if FIND-SET(u) != FIND-SET(v):
		add {(u, v)} to set MST
		UNION(u, v)

return MST


*/

#include <iostream>
#include <algorithm>
using namespace std;


//Struct on an undirected edge (u, v) having weight
struct Edge {
	int u, v, weight;
};

//data structure for union-find
class UnionFind {
	int *id, *sz, cnt;
public:
	UnionFind(int N) {
		cnt = N;
		id = new int[N];
		sz = new int[N];

		//setting each element of the two arrays to 1 through N.
		for (int i = 0; i < N; i++) {
			id[i] = i;
			sz[i] = i;
		}
	}

	//deconstructor to help manage memory
	~UnionFind() {
		delete[] id;
		delete[] sz;
	}

	//returning the id of componenet corresponding to the object P
	int find(int p) {
		int root = p;
		while (root != id[root])
			root = id[root];
		while (p != root) {
			int newp = id[p];
			id[p] = root;
			p = newp;
		}
		return root;
	}

	void merge(int x, int y) {
		int i = find(x);
		int j = find(y);
		if (i == j)
			return;
		if (sz[i] < sz[j]) {
			id[i] = j;
			sz[j] += sz[i];
		}

		else {
			id[j] = i;
			sz[i] += sz[j];
		}
		cnt--;
	}

	//are the objects x and y in the same set?
	bool isConnected(int x, int y) {
		return find(x) == find(y);
	}

	int getCount() {
		return cnt;
	}
};

bool comp(Edge *a, Edge *b) {
	return a->weight < b->weight;
}

int main() {
	int V, E, i, N, u, v, cost;
	Edge **edges, **mst;

	cin >> *(&V), *(&E);
	edges = new Edge* [E];
	for (i = 0; i < E; i++) {
		edges[i] = new Edge;
		cin >> *(&(edges[i]->u), &(edges[i]->v), &(edges[i]->weight));
	}
	sort(edges, edges + E, comp);

	UnionFind uf(V);
	mst = new Edge*[V - 1];
	for (N = i = cost = 0; i < E && N < V - 1; i++) {
		u = edges[i]->u; v = edges[i]->v;
		if (!uf.isConnected(u, v)) {
			uf.merge(u, v);
			mst[N++] = edges[i];
			cost += edges[i]->weight;
		}
	}

	cout << "Total cost of MST: %d\n", cost;
	cout << "Edges in MST: \n";
	for (i = 0; i < N; i++) {
		cout << mst[i]->u, mst[i]->v, mst[i]->weight;

	}

	return 0;

}


