#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include "Vertex.h"
#include "Edge.h"
#include "Methods.h"
using namespace std;

class Graph
{
private:
	int numVertices; // Number of vertices
	vector<Vertex> vertexList = vector<Vertex>(); // List of nodes
	vector<Edge*> neighbersList = vector<Edge*>();

	bool EdgeExists(int u, int v);
	void ReadGraphFromUser();
	void SortAllNeighbers();
	void SortAllEdges();

public:
	Graph();
	~Graph();
	void UnmarkAllEdges();

	// ----------------Get & Set ------------------- //
	void GetEdgesFromUser();
	vector<Vertex>& GetVertexsList() { return vertexList; }
	int GetNumVertices() { return numVertices; }
};

