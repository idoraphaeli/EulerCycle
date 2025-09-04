#include "Graph.h"

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

			nodes[startEdge].AddNeighber(endEdge);
			nodes[endEdge].AddNeighber(startEdge);

			Edge* edge = new Edge(&nodes[startEdge], &nodes[endEdge]);
			Edge* twinEdge = new Edge(&nodes[endEdge], &nodes[startEdge]);

			edge->setTwin(twinEdge);
			twinEdge->setTwin(edge);

			edges.push_back(edge);
			edges.push_back(twinEdge);
		}
		
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}

	ListNeighbers = edges;
}
