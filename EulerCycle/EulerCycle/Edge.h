#pragma once
#include <iostream>

class Vertex;

class Edge
{
	private:
		bool Marked = false;
		Vertex* Start = nullptr;
		Vertex* End = nullptr;
		Edge* twin = nullptr;
	public:
		Edge(Vertex* node1, Vertex* node2);
		Edge* getTwin() const;
		void setTwin(Edge* e);

		Vertex* getStart() const { return Start; }
		Vertex* getEnd() const { return End; }

		void mark() { Marked = true; }
		bool isMarked() const { return Marked; }
		void SetMark(bool mark) { Marked = mark; }
};

