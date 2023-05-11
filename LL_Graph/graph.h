#ifndef _GRAPH
#define _GRAPH

#include <vector>
#include "edge.h"
#include "Node.h"

typedef std::pair<int, int> Pair; // to hold (dest, weight) tuple

template<class ItemType>
class Graph {
	// declare a vector of vectors of Pairs to store the Adj list
	std::vector<Node*> adjList;
public:
	Graph(std::vector<Edge<int>> const& edges, int N) {
		int src = 0;
		int dest = 0;
		bool nodeExists = false;
		// add edges to digraph
		for (Edge<int> edge : edges) {
			src = edge.getSrc();
			dest = edge.getDest();
			std::cout << "adding source at " << src << "with dest" << dest << std::endl;

			if (!adjList.empty()) {
				for (Node* node : adjList) {
					if (src == node->getNodeValue()) {
						nodeExists = true;
						break;
					}
				}
			}

			std::cout << src << (nodeExists ? "Exists" : " does not exist") << std::endl;
			// if the src exists in vector<Node*>, add a new node at the end of it
			if (nodeExists) {
				Node* cur = adjList[src];
				while (cur->getNextNode() != nullptr) {
					cur = cur->getNextNode();
				}
				cur->setNextNode(new Node(dest));
				std::cout << " --> " << dest <<
			}
			// otherwise, push a new node to vector<Node*>, and add a new node as root
			else {
				adjList.push_back(new Node(src));
				Node* cur = adjList.at(src - 1);
				cur->setNextNode(new Node(dest));
				std::cout << "New Node and dest added." << std::endl;
			}
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