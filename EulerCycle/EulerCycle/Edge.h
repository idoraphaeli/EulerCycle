#pragma once
#include "Node.h"

class Edge
{
	private:
		bool Marked = false;
		Node* Start = nullptr;
		Node* End = nullptr;
		Edge* twin = nullptr;
	public:
		Edge(Node* node1, Node* node2);
		Edge* getTwin() const;
		void setTwin(Edge* e);
};

