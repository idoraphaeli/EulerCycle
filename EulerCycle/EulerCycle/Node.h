#pragma once
class Vertex;
class Node
{
	Vertex* V;
	Node* Next = nullptr;

public:
	Node(Vertex* v) : V(v){}
	void SetNext(Node* next) { Next = next; }
	Node* GetNext() { return Next; }
	Vertex* GetVertex() { return V; }
};

