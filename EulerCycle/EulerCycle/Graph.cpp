#include "Graph.h"

Graph::Graph() {
	ReadGraphFromUser();
}

void Graph::ReadGraphFromUser() {
	int numOfEdges = 0;
	vector<Node> nodes;

	cout << "Enter number of vertices: ";
	numVertices = Methods::GetPositiveIntegerFromUser();

	nodes.reserve(numVertices + 1);
	nodes.emplace_back(0); // dummy
	for (int i = 1; i < numVertices + 1; i++) {
		nodes.emplace_back(i);
	}

	nodesList = nodes;
	cout << "Please enter the edges of the graph: ";
	GetEdgesFromUser();
}

void Graph::UnmarkAllEdges() {
	for (Edge* edge : neighbersList) {          // עבור כל צומת בגרף
		edge->SetMark(false);
	}
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
			throw invalid_argument("No input was provided.");
		}

		for (char c : input) {
			if (!isdigit(c) && c != ' ') {
				throw invalid_argument("Input is not a valid number.");
			}
		}

		istringstream iss(input);

		while (iss >> startEdge >> endEdge) {
			if ((startEdge <= 0) || (endEdge <= 0)) {
				throw invalid_argument("Number of vertices must be positive.");
			}

			nodesList[startEdge].AddNeighber(endEdge);
			nodesList[endEdge].AddNeighber(startEdge);

			Edge* edge = new Edge(&nodesList[startEdge], &nodesList[endEdge]);
			Edge* twinEdge = new Edge(&nodesList[endEdge], &nodesList[startEdge]);

			edge->setTwin(twinEdge);
			twinEdge->setTwin(edge);

			nodesList[startEdge].AddEdge(edge);
			nodesList[endEdge].AddEdge(twinEdge);

			edges.push_back(edge);
			edges.push_back(twinEdge);
		}
		
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}

	neighbersList = edges;
}
