#include <iostream>
#include <vector>
#include <chrono>
#include "Methods.h"
#include "Euler.h"

using namespace std;

int main() {
    Graph g;
    Euler e = Euler(g);

    int Efficient = Methods::AskEfficientcy();
    bool showRunTime = Methods::AskShowRuntime();

    auto start = chrono::high_resolution_clock::now();

    if (e.IsEulerian()) {

        switch (Efficient) {
        case 1: {
            e.FindEulerCycleEfficient();
            e.PrintCycle();
            break;
        }
        case 2: {
            e.FindEulerCycleInefficient();
            e.PrintCycle();
            break;
        }
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration =
            chrono::duration_cast<chrono::microseconds>(end - start);

        if (showRunTime) {
            cout << "\nFunction took " << duration.count() << " microseconds." << endl;
        }
    }
    else {
        cout << "Graph is not Eulerian." << endl;
    }
}
