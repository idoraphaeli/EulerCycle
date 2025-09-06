#pragma once
#include <vector>
using namespace std;

class Edge; // Forward declaration
class Node
{
	public:
		enum class Color { White, Gray, Black };

	private:
		int NodeNum = -1;
		Color color = Color::White;
		vector<int> Neighbers = vector<int>();
		vector<Edge*> Edges = vector<Edge*>();
		Node* nextInCycle = nullptr;
		int currentNeighbers = 0;

	public:
		Node(int Num) { NodeNum = Num; };
		void AddNeighber(int Neighber) { Neighbers.push_back(Neighber); currentNeighbers++; };
		void AddEdge(Edge* e) { Edges.push_back(e); };
		void MarkEdgeTo(int neighborId);

		// -----------------Get & Set------------------- //
		void setColor(Color c) { color = c; }
		Color GetColor() const { return color; }
		int const GetDegree() const { return Neighbers.size(); }
		vector<int>& const GetNeighbers() { return Neighbers; }
		vector<Edge*>& const GetEdges() { return Edges; }
		int const GetNodeNum() const { return NodeNum; }
		void SetNext(Node* n) { nextInCycle = n; }
		Node* GetNext() const { return nextInCycle; }
		int& GetCurrentNeighbers() { return currentNeighbers; }
		

};

