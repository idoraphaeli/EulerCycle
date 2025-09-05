#include <iostream>
#include <vector>
#include "Methods.h"
#include "Euler.h"

using namespace std;

int main() {
    Graph g;
    Euler e = Euler(g);

    if (e.IsEulerian()) {
        cout << "IsEulerian";
        e.FindEulerCycle();
        e.PrintCycle();
    }
    else {
        cout << "Not Eulerian";
        // output not eulerian
    }
}
