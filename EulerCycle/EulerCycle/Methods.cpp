#include "Methods.h"

bool Methods::AskShowRuntime() {
	
	bool willBeShown = false;
	cout << "Would you like to see the runtime of the algorithm?";
	int answer = GetPositiveIntegerFromUser();

	try{
		if (answer != 0 && answer != 1) {
			throw invalid_argument("Input should be 0 or 1.");
		}
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}

	return answer == 0 ? false : true;
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
