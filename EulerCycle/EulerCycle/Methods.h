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
		vector<int> FindEulerCycle(Node* CycleHead);
		int GetPositiveIntegerFromUser();
		Graph ReadGraphFromUser();
		void AddCircuit(Node* cycleHead);
		Node* FindCircuit(int i);
		void AddNode();
		void PrintCycle();
};

