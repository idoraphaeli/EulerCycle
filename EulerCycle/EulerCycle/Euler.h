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
		vector<Node*>& FindCircuitOptimized(int i);
		bool IsConnected();
		bool AreAllVerticesEvenDegree();
		void Visit(Node* vertex);

	public:
		Euler(Graph graph) : graph(graph) {}
		void FindEulerCycle();
		void PrintCycle();
		bool IsEulerian();
		static bool AllVertexsAreMarked(vector<Node*>& L);

		// ---------------Get & Set----------------- //
		Node* getEulerHead();
		void setCurrent(Node* Curr);
		Node* getCurrent();
		void setShowRuntime(bool isShow);
		bool getShowRuntime();
		void setEulerHead(Node* EulerHead);
		
};

