#include <iostream>
#include <vector>
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
        case 1:
            e.FindEulerCycle();
            e.PrintCycle();
            break;

        case 2:
            e.FindEulerCycle();
            e.PrintCycle();
            break;
        }
    }
}
