#include "Methods.h"

Node* Methods::FindCircuit(int i) {
	Node* cycleHead = nullptr;

	return cycleHead;
}

void Methods::AddCircuit(Node* cycleHead) {

}

void Methods::AddNode(){

}

vector<int> Methods:: FindEulerCycle() {
	ReadGraphFromUser();

	return vector<int>();
}

void Methods::PrintCycle() {

}

Graph Methods::ReadGraphFromUser() {
	int numOfVertices = 0;
	int numOfEdges = 0;
	vector<Node> nodes;

	cout << "Enter number of vertices: ";
	numOfVertices = Methods::GetPositiveIntegerFromUser();
	nodes.reserve(numOfVertices+1);
	nodes.emplace_back(0); // dummy
	for (int i = 1; i < numOfVertices+1; i++) {
		nodes.emplace_back(i);
	}

	Graph graph(numOfVertices, nodes);

	cout << "Please enter the edges of the graph: ";
	graph.GetEdgesFromUser();
	
	return graph;
}

int Methods::GetPositiveIntegerFromUser() {
	string input;
	int number = 0;
	cin >> input;

	try {

		if (input.empty()) {
			throw invalid_argument("No input was provided.");
		}

		for (char c : input) {
			if (!isdigit(c)) {
				throw invalid_argument("Input is not a valid number.");
			}
		}

		number = stoi(input);
		if (number <= 0) {
			throw invalid_argument("Number of vertices must be positive.");
		}
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
	return number;
}
