#pragma once
#include <vector>
using namespace std;

class Edge; // Forward declaration
class Vertex
{
	public:
		enum class Color { White, Gray, Black };

	private:
		int VertexNum = -1;
		Color color = Color::White;
		vector<int> Neighbers = vector<int>();
		vector<Edge*> Edges = vector<Edge*>();
		Vertex* nextInCycle = nullptr;
		int currentNeighbers = 0;
		int nextEdgeIndex = 0;

	public:
		Vertex(int Num) { VertexNum = Num; };
		void AddNeighber(int Neighber) { Neighbers.push_back(Neighber); currentNeighbers++; };
		void AddEdge(Edge* e) { Edges.push_back(e); };
		void MarkEdgeTo(int neighborId);

		// -----------------Get & Set------------------- //
		void setColor(Color c) { color = c; }
		Color GetColor() const { return color; }
		int const GetDegree() const { return Neighbers.size(); }
		vector<int>& GetNeighbers() { return Neighbers; }
		vector<Edge*>& GetEdges() { return Edges; }
		int const GetVertexNum() const { return VertexNum; }
		void SetNext(Vertex* n) { nextInCycle = n; }
		Vertex* GetNext() const { return nextInCycle; }
		int& GetCurrentNeighbers() { return currentNeighbers; }
		int& GetNextEdgeIndex() { return nextEdgeIndex; }
		void SetNextEdgeIndex(int Index) { nextEdgeIndex = Index; }
		

};

