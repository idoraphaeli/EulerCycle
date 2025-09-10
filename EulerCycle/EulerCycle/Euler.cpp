#include "Euler.h"

Euler::~Euler() {
	Node* curr = EulerHead;
	while (curr != nullptr) {
		Node* next = curr->GetNext();
		delete curr;
		curr = next;
	}
}

void Euler::AddCircuit(Node* currentL1) {

	int stop = currentL1->GetVertex()->GetVertexNum();

	if (EulerHead == nullptr) {
		EulerHead = currentL1;
		return;
	}

	Node* currentL = EulerHead;

	while (currentL != nullptr && currentL->GetVertex()->GetVertexNum() != stop) {
		currentL = currentL->GetNext();
	}

	Node* nodeToInsert = currentL1->GetNext();
	Node* pos = currentL;

	while (nodeToInsert != nullptr) {
		Node* nextInCycle = nodeToInsert->GetNext();
		AddNode(pos, nodeToInsert);
		pos = nodeToInsert;
		nodeToInsert = nextInCycle;
	}

}

void Euler::AddNode(Node* pos, Node* newNode) {
	if (pos == nullptr || newNode == nullptr) return;

	Node* after = pos->GetNext();
	pos->SetNext(newNode);
	newNode->SetNext(after);
}

void Euler::FindEulerCycleEfficient() {
	int i = 1;
	graph.UnmarkAllEdges();

	Node* newCycle = nullptr;
	Current = new Node(&graph.GetVertexsList()[i]);
	EulerHead = Current;

	while (Current != nullptr) {

		bool hasUnmarkedEdge = false;
		while (Current->GetVertex()->GetNextEdgeIndex() < Current->GetVertex()->GetEdges().size()) {
			Edge* e = Current->GetVertex()->GetEdges()[Current->GetVertex()->GetNextEdgeIndex()];
			Current->GetVertex()->GetNextEdgeIndex()++;

			if (!e->isMarked()) {
				hasUnmarkedEdge = true;
				break;
			}
		}

		if (hasUnmarkedEdge) {
			Node* extraCycle = FindCircuit(Current->GetVertex()->GetVertexNum());

			AddCircuit(extraCycle);
			Current = extraCycle->GetNext();
			continue;
		}
		Current = Current->GetNext();
	}
}

void Euler::FindEulerCycleInefficient() {
	int i = 1;
	graph.UnmarkAllEdges();

	Node* newCycle = nullptr;
	Current = new Node(&graph.GetVertexsList()[i]);
	EulerHead = Current;

	while (Current != nullptr) {

		bool hasUnmarkedEdge = false;
		for (Edge* edge : Current->GetVertex()->GetEdges()) {
			bool twinIsMarked = false;
			Vertex* endVertex = edge->getEnd();

			if (!edge->isMarked()) {

				for (Edge* edge : endVertex->GetEdges()) {

					if (edge->getEnd()->GetVertexNum() == Current->GetVertex()->GetVertexNum()) {
						if (!edge->isMarked()) {
							hasUnmarkedEdge = true;
							break;
						}
					}
				}
				if (hasUnmarkedEdge) break;
			}
		}

		if (hasUnmarkedEdge) {
			Node* extraCycle = FindCircuit(Current->GetVertex()->GetVertexNum());

			AddCircuit(extraCycle);
			Current = EulerHead;
			continue;
		}
		else {
			Current = Current->GetNext();
		}
	}
}

Node* Euler::FindCircuit(int i) {

	Vertex* startVertex = &graph.GetVertexsList()[i];
	Node* res = new Node(startVertex);
	Node* currentNode = res;
	Vertex* current = startVertex;

	while (true) {
		bool moved = false;
		vector<Edge*> edgeList = current->GetEdges();

		for (Edge* e : edgeList) {
			if (!e->isMarked()) {
				e->SetMark(true);
				e->getTwin()->SetMark(true);

				Vertex* End = e->getEnd();

				current->GetCurrentNeighbers()--;
				End->GetCurrentNeighbers()--;

				Node* next = new Node(End);
				currentNode->SetNext(next);
				currentNode = next;

				current = End;
				moved = true;
				break;
			}
		}

		if (!moved) {
			break;
		}

	}

	return res;
}

void Euler::PrintCycle() {
	Node* curr = EulerHead;
	cout << "Euler circuit: ";

	while (curr->GetNext() != nullptr) {
		cout << curr->GetVertex()->GetVertexNum() << ", ";
		curr = curr->GetNext();
	}
	cout << curr->GetVertex()->GetVertexNum();
}

bool Euler::IsEulerian() {
	return IsConnected() && AreAllVerticesEvenDegree();
}

bool Euler::AreAllVerticesEvenDegree() {
	bool EvenDegree = true;

	for (const Vertex& node : graph.GetVertexsList()) {
		if (node.GetDegree() % 2 != 0) {
			EvenDegree = false;
			break;
		}
	}

	return EvenDegree;
}

bool Euler::IsConnected() {
	bool IsConnected = true;
	Visit(&graph.GetVertexsList()[1]);

	for (int i = 1; i < graph.GetNumVertices()+1; i++)
	{
		if (graph.GetVertexsList()[i].GetColor() == Vertex::Color::White) {
			IsConnected = false;
			break;
		}
	}

	return IsConnected;
}

void Euler::Visit(Vertex* vertex) {
	vertex->setColor(Vertex::Color::Gray);
	
	for (int nodeNumber : vertex->GetNeighbers()) {
		if (graph.GetVertexsList()[nodeNumber].GetColor() == Vertex::Color::White) {
			vertex->MarkEdgeTo(nodeNumber);
			Visit(&graph.GetVertexsList()[nodeNumber]);
		}
	}
	vertex->setColor(Vertex::Color::Black);
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