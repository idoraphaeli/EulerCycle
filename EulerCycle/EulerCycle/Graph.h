#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Node.h"
#include "Edge.h"
#include "Methods.h"
using namespace std;

class Graph
{
private:
	int numVertices; // Number of vertices
	vector<Node> nodesList; // List of nodes
	vector<Edge*> neighbersList;

	void ReadGraphFromUser();

public:
	Graph();

	// ----------------Get & Set ------------------- //
	void GetEdgesFromUser();
	vector<Node>& GetNodesList() { return nodesList; }
	int GetNumVertices() { return numVertices; }
};

