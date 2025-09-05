#include "Edge.h"
#include "Node.h"

Edge::Edge(Node* node1, Node* node2){
	Start = node1;
	End = node2;
}

void Edge::setTwin(Edge* e) { twin = e; }

Edge* Edge::getTwin() const { return twin; }