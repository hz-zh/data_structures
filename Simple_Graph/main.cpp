#include <iostream>
#include <vector>
#include "edge.h"
#include "graph.h"

int main() {
	std::vector<Edge<int>> edges;

	Edge<int> e;
	e.setSrcDstWeight(1, 2, 1); edges.push_back(e);
	e.setSrcDstWeight(2, 4, 5); edges.push_back(e);
	e.setSrcDstWeight(1, 3, 2); edges.push_back(e);
	e.setSrcDstWeight(3, 5, 4); edges.push_back(e);
	e.setSrcDstWeight(3, 4, 2); edges.push_back(e);
	e.setSrcDstWeight(4, 7, 1); edges.push_back(e);
	e.setSrcDstWeight(3, 6, 3); edges.push_back(e);

	int N = 7;

	Graph myGraph(edges, N);

	myGraph.printGraph(N);
}