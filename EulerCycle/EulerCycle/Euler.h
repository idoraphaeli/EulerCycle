#pragma once
#include "Node.h"
#include "Graph.h"
#include <vector>

class Euler
{
	private:
		Graph graph;
		Node* EulerHead = nullptr;
		Node* Current = nullptr;
		bool showRuntime = false;

		void AddNode();
		void AddCircuit(Node* cycleHead);
		Node* FindCircuit(int i);
		bool IsConnected();
		bool AreAllVerticesEvenDegree();
		void Visit(Node* vertex);

	public:
		Euler(Graph graph) : graph(graph) {}
		void setEulerHead(Node* EulerHead);
		vector<int> FindEulerCycle();
		void PrintCycle();
		Node* getEulerHead();
		void setCurrent(Node* Curr);
		Node* getCurrent();
		void setShowRuntime(bool isShow);
		bool getShowRuntime();
		bool IsEulerian();
};

