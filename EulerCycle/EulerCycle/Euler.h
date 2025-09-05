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
		void PrintCycle();
		void AddCircuit(Node* cycleHead);
		Node* FindCircuit(int i);
		vector<int> FindEulerCycle();

	public:
		Euler(Graph graph) : graph(graph) {}
		void setEulerHead(Node* EulerHead);
		Node* getEulerHead();
		void setCurrent(Node* Curr);
		Node* getCurrent();
		void setShowRuntime(bool isShow);
		bool getShowRuntime();
};

