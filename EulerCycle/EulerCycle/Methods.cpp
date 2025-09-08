#include "Methods.h"

bool Methods::AskShowRuntime() {
	
	bool willBeShown = false;
	int answer = GetPositiveIntegerFromUser();
	
	try{
		if (answer != 0 && answer != 1) {
			throw invalid_argument("Invalid input.");
		}
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
		exit(1);
	}

	return answer == 0 ? false : true;
}

int Methods::AskEfficientcy() {

	bool willBeShown = false;
	int answer = GetPositiveIntegerFromUser();

	try {
		if (answer != 2 && answer != 1) {
			throw invalid_argument("Invalid input.");
		}
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
		exit(1);
	}

	return answer;
}


int Methods::GetPositiveIntegerFromUser() {
	string input;
	int number = 0;
	cin >> input;

	try {

		if (input.empty()) {
			throw invalid_argument("Invalid input.");
		}

		for (char c : input) {
			if (!isdigit(c)) {
				throw invalid_argument("Invalid input.");
			}
		}
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
		exit(1);
	}

	number = stoi(input);
	return number;
}
