#include <iostream>
#include <vector>
#include "Methods.h"
#include "Euler.h"

using namespace std;

int main() {
    Graph g;
    Euler e = Euler(g);

    if (e.IsEulerian()) {
        e.FindEulerCycle();
        e.PrintCycle();
    }
    else {
        // output not eulerian
    }
}
