#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "Graph.h"
using namespace std;

class Methods
{
	private:
		void AddCircuit(Node* cycleHead);
		Node* FindCircuit(int i);
		void AddNode();
		void PrintCycle();
	public:
		static vector<int> FindEulerCycle();
		static Graph ReadGraphFromUser();
		static int GetPositiveIntegerFromUser();
		static vector<Edge> GetEdgesFromUser();
};

