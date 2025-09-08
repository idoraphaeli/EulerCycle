#include "Graph.h"

Graph::Graph() {
	ReadGraphFromUser();
	SortAllNeighbers();
	SortAllEdges();
}

/*Graph::~Graph() {
	for (Vertex& v : vertexList) {
		for (Edge* e : v.GetEdges()) {
			delete e;
		}
	}
}*/

void Graph::ReadGraphFromUser() {
	int numOfEdges = 0;
	vector<Vertex> nodes;

	numVertices = Methods::GetPositiveIntegerFromUser();

	nodes.reserve(numVertices + 1);
	nodes.emplace_back(0); // dummy
	for (int i = 1; i < numVertices + 1; i++) {
		nodes.emplace_back(i);
	}

	vertexList = nodes;
	GetEdgesFromUser();
}

void Graph::SortAllEdges() {
	for (Vertex& v : vertexList) {
		vector<Edge*>& edges = v.GetEdges();
		sort(edges.begin(), edges.end(),
			[](Edge* a, Edge* b) {
				if (a->getStart()->GetVertexNum() != b->getStart()->GetVertexNum()) {
					return a->getStart()->GetVertexNum() < b->getStart()->GetVertexNum();
				}
				return a->getEnd()->GetVertexNum() < b->getEnd()->GetVertexNum();
			});
	}
}

void Graph::SortAllNeighbers() {
	for (Vertex& v : vertexList) {
		vector<int>& neigh = v.GetNeighbers();
		sort(neigh.begin(), neigh.end());
	}
}

void Graph::UnmarkAllEdges() {
	for (Edge* edge : neighbersList) {
		if (edge->isMarked()) {
			edge->SetMark(false);
			edge->getTwin()->SetMark(false);
			edge->getStart()->GetCurrentNeighbers()++;
			edge->getEnd()->GetCurrentNeighbers()++;
		}
	}
}

bool Graph::EdgeExists(int u, int v) {
	bool res = false;

	for (Edge* e : vertexList[u].GetEdges()) {
		if (e->getEnd()->GetVertexNum() == v) {
			res = true;
			break;
		}
	}

	if (!res) {
		for (Edge* e : vertexList[v].GetEdges()) {
			if (e->getEnd()->GetVertexNum() == u) {
				res = true;
				break;
			}
		}
	}

	return res;
}

void Graph::GetEdgesFromUser() {
	vector<Edge*> edges;
	string input;
	int startEdge = 0;
	int endEdge = 0;
	cin.ignore();
	getline(cin,input);

	try {

		if (input.empty()) {
			return;
		}

		for (char c : input) {
			if (!isdigit(c) && c != ' ') {
				throw invalid_argument("Invalid input.");
			}
		}

		istringstream iss(input);

		while (iss >> startEdge >> endEdge) {
			if ((startEdge <= 0) || (startEdge > numVertices) || (endEdge <= 0) || (endEdge > numVertices)) {
				throw invalid_argument("Invalid input.");
			}

			if (EdgeExists(startEdge, endEdge)) {
				throw invalid_argument("Invalid input.");
			}

			vertexList[startEdge].AddNeighber(endEdge);
			vertexList[endEdge].AddNeighber(startEdge);

			Edge* edge = new Edge(&vertexList[startEdge], &vertexList[endEdge]);
			Edge* twinEdge = new Edge(&vertexList[endEdge], &vertexList[startEdge]);

			edge->setTwin(twinEdge);
			twinEdge->setTwin(edge);

			vertexList[startEdge].AddEdge(edge);
			vertexList[endEdge].AddEdge(twinEdge);

			edges.push_back(edge);
			edges.push_back(twinEdge);
		}
		
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
		exit(1);
	}

	neighbersList = edges;
}
