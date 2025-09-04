#pragma once
#include <vector>
using namespace std;

class Edge; // Forward declaration
class Node
{
	private:
		int NodeNum = -1;
		vector<int> Neighbers = vector<int>();

	public:
		Node(int Num) { NodeNum = Num; };
		void AddNeighber(int Neighber) { Neighbers.push_back(Neighber); };
};

