#pragma once

class Graph
{
private:
	int numVertices; // Number of vertices
	vector<Edge> ListNeighbers;
public:
	Graph(int v, vector<Edge> edges) : numVertices(v), ListNeighbers(edges) {}
};

