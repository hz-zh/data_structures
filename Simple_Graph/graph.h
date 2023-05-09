#ifndef _GRAPH
#define _GRAPH

#include <vector>
#include "edge.h"

typedef std::pair<int, int> Pair; // to hold (dest, weight) tuple

class Graph {
	// declare a vector of vectors of Pairs to store the Adj list
	std::vector<std::vector<Pair>> adjList;
public:
	Graph(std::vector<Edge<int>> const& edges, int N) {
		// resize adjList to N elements
		adjList.resize(N);

		// add edges to digraph
		for (Edge<int> edge : edges) {
			int src = edge.getSrc();
			int dest = edge.getDest();
			int weight = edge.getWeight();

			//insert at the end
			adjList[src].push_back(std::make_pair(dest, weight));
		}
	}

	void printGraph(int N) {
		for (int i = 0; i < N; i++) {
			for (Pair v : adjList[i]) {
				std::cout << i << "-->" << v.first << "(w/" << v.second << ")";
				std::cout << "\n";
			}
		}
	}
};

#endif 