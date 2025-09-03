#pragma once
#include <vector>
using namespace std;

class Edge; // Forward declaration
class Node
{
	private:
		int NodeNum = -1;
		vector<Edge> Edges;
};

