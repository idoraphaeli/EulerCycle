#pragma once
#include "Vertex.h"
#include "Graph.h"
#include "Node.h"
#include <vector>

class Euler
{
	private:
		Graph graph;
		Node* EulerHead = nullptr;
		Node* Current = nullptr;
		bool showRuntime = false;

		void AddNode(Node* pos, Node* newNode);
		void AddCircuit(Node* cycleHead);
		Node* FindCircuit(int i);
		bool IsConnected();
		bool AreAllVerticesEvenDegree();
		void Visit(Vertex* vertex);

	public:
		Euler(Graph graph) : graph(graph) {}
		void FindEulerCycle();
		void PrintCycle();
		bool IsEulerian();

		// ---------------Get & Set----------------- //
		Node* getEulerHead();
		void setCurrent(Node* Curr);
		Node* getCurrent();
		void setShowRuntime(bool isShow);
		bool getShowRuntime();
		void setEulerHead(Node* EulerHead);
		
};

