#pragma once
class Node;

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

		Node* getStart() const { return Start; }
		Node* getEnd() const { return End; }

		void mark() { Marked = true; }
		bool isMarked() const { return Marked; }
};

