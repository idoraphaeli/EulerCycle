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
            e.FindEulerCycle();
            e.PrintCycle();
            auto end = chrono::high_resolution_clock::now();
            auto duration =
                std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            if (showRunTime) {
                std::cout << "\nFunction took " << duration.count() << " microseconds." << std::endl;
            }
            break;
        }
        case 2: {
            auto start = chrono::high_resolution_clock::now();
            e.FindEulerCycle();
            e.PrintCycle();
            auto end = chrono::high_resolution_clock::now();
            auto duration =
                std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            if (showRunTime) {
                std::cout << "\nFunction took " << duration.count() << " microseconds." << std::endl;
            }
            break;
        }
        }
    }
}
