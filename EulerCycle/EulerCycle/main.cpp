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

    if (e.IsEulerian()) {

        switch (Efficient) {
        case 1: {
            auto start = chrono::high_resolution_clock::now();
            e.FindEulerCycleEfficient();
            e.PrintCycle();
            auto end = chrono::high_resolution_clock::now();
            auto duration =
                chrono::duration_cast<chrono::microseconds>(end - start);
            if (showRunTime) {
                cout << "\nFunction took " << duration.count() << " microseconds." << endl;
            }
            break;
        }
        case 2: {
            auto start = chrono::high_resolution_clock::now();
            e.FindEulerCycleInefficient();
            e.PrintCycle();
            auto end = chrono::high_resolution_clock::now();
            auto duration =
                chrono::duration_cast<chrono::microseconds>(end - start);
            if (showRunTime) {
                cout << "\nFunction took " << duration.count() << " microseconds." << endl;
            }
            break;
        }
        }
    }
    else {
        cout << "Graph is not Eulerian." << endl;
    }
}
