#include "Edge.h"
#include "Vertex.h"

Edge::Edge(Vertex* node1, Vertex* node2){
	Start = node1;
	End = node2;
}

void Edge::setTwin(Edge* e) { twin = e; }

Edge* Edge::getTwin() const { return twin; }