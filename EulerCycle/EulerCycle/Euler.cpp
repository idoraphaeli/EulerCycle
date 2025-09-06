#include "Euler.h"

void Euler::AddCircuit(Node* cycleHead) {
	
	/*
	Node* current = EulerHead;

	if (EulerHead == nullptr) {
		EulerHead = cycleHead;
		return;
	}

	while (current != nullptr && current != cycleHead) {
		current = current->GetNext();
	}

	Node* newCycleHead = FindCircuitOptimized(cycleHead->GetNodeNum());

	Node* after = current->GetNext();
	Node* tail = newCycleHead;

	while (tail->GetNext() != nullptr && tail != newCycleHead) {
		tail = tail->GetNext();
	}

	if (newCycleHead->GetNext() != nullptr) {
		tail->SetNext(after);
		current->SetNext(newCycleHead->GetNext());
	}
	*/
}

void Euler::AddNode() {

}

void Euler::FindEulerCycle() {
	int i = 1;
	vector<Node*> L;
	graph.UnmarkAllEdges();
	L.push_back(&graph.GetNodesList()[1]);
	vector<Node*> newCycle = FindCircuitOptimized(i);
	Current = &graph.GetNodesList()[1];
	
	while (!AllVertexsAreMarked(L)) {

	}
	
}

bool Euler::AllVertexsAreMarked(vector<Node*>& L) {
	bool AllVertexsAreMarked = true;

	for (int i = 0; i < L.size(); i++)
	{
		if (L[i]->GetCurrentNeighbers() > 0) {
			AllVertexsAreMarked = false;
			break;
		}
	}

	return AllVertexsAreMarked;
}

vector<Node*>& Euler::FindCircuitOptimized(int i) {

	Node startNode = graph.GetNodesList()[i];
	vector<Node*> L;
	Node* current = &startNode;
	L.push_back(&startNode);

	while (current->GetCurrentNeighbers() > 0) {
		int n = current->GetEdges().size();
		vector<Edge*> edgeList = current->GetEdges();

		for (int i = 0; i < n; i++)
		{
			if (!edgeList[i]->isMarked()) {
				Edge* unmarkedEdge = edgeList[i];
				Node* Start = unmarkedEdge->getStart();
				Node* End = unmarkedEdge->getEnd();
				L.push_back(End);
				current = End;
			}
		}
	}

	return L;
}

void Euler::PrintCycle() {
	
}

bool Euler::IsEulerian() {
	return IsConnected() && AreAllVerticesEvenDegree();
}

bool Euler::AreAllVerticesEvenDegree() {
	bool EvenDegree = true;

	for (const Node& node : graph.GetNodesList()) {
		if (node.GetDegree() % 2 != 0) {
			EvenDegree = false;
			break;
		}
	}

	return EvenDegree;
}

bool Euler::IsConnected() {
	bool IsConnected = true;
	Visit(&graph.GetNodesList()[1]);

	for (int i = 1; i < graph.GetNumVertices(); i++)
	{
		if (graph.GetNodesList()[i].GetColor() == Node::Color::White) {
			IsConnected = false;
			break;
		}
	}

	return IsConnected;
}

void Euler::Visit(Node* vertex) {
	vertex->setColor(Node::Color::Gray);
	
	for (int nodeNumber : vertex->GetNeighbers()) {
		if (graph.GetNodesList()[nodeNumber].GetColor() == Node::Color::White) {
			vertex->MarkEdgeTo(nodeNumber);
			Visit(&graph.GetNodesList()[nodeNumber]);
		}
	}
	vertex->setColor(Node::Color::Black);
}

// -----------------------------Get & Set----------------------------------//

void Euler::setShowRuntime(bool isShow) {
	showRuntime = isShow;
}
bool Euler::getShowRuntime() {
	return showRuntime;
}

void Euler::setEulerHead(Node* Head) {
	EulerHead = Head;
}

Node* Euler::getEulerHead() {
	return EulerHead;
}

void Euler::setCurrent(Node* Curr) {
	Current = Curr;
}

Node* Euler::getCurrent() {
	return Current;
}