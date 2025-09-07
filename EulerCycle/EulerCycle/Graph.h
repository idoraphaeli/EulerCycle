#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Vertex.h"
#include "Edge.h"
#include "Methods.h"
using namespace std;

class Graph
{
private:
	int numVertices; // Number of vertices
	vector<Vertex> nodesList; // List of nodes
	vector<Edge*> neighbersList;

	void ReadGraphFromUser();

public:
	Graph();
	void UnmarkAllEdges();

	// ----------------Get & Set ------------------- //
	void GetEdgesFromUser();
	vector<Vertex>& GetVertexsList() { return nodesList; }
	int GetNumVertices() { return numVertices; }
};

