#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Node.h"
#include "Edge.h"
using namespace std;

class Graph
{
private:
	int numVertices; // Number of vertices
	vector<Node> nodes; // List of nodes
	vector<Edge*> ListNeighbers;

public:
	Graph(int v, vector<Node> nodes) : numVertices(v), nodes(nodes) {}
	void setListNeighbersSize(vector<Edge*> edges) { ListNeighbers = edges; }
	void GetEdgesFromUser();
};

