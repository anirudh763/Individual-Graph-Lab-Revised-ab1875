/*
 * CSCE Graph Lab 1 - Individual Work
 * Description: Runs input/output and walk analysis using Graph class.
 * External Resources Used: NONE
 */

#include <iostream>
#include "Graph.h"
#include <vector>

using namespace std;

int main() {
    int size;

    cout << "Total number of vertices in the graph? ";
    cin >> size;

    if (size < 0) {
        cout << "Vertex count must be non-negative. Terminating.\n";
        return 1;
    }

    Graph myGraph(size);

    myGraph.inputConnections();

    myGraph.showGraph();

    char response;
    cout << "Do you like to validate a walk and view its properties? (y/n): ";
    cin >> response;

    if (response == 'y' || response == 'Y') {
        vector<int> path;
        int node;
        cout << "Enter walk (start and end with a vertex, -1 to stop):\n";
        while (cin >> node && node != -1) {
            if (node < 0 || node >= size) {
                cout << "Invalid vertex. Try again.\n";
                continue;
            }
            path.push_back(node);
        }

        if (path.size() < 2) {
            cout << "Walk too short.\n";
        } else {
            if (myGraph.checkTheWalkValidity(path)) {
                cout << "VALID WALK\n";
                myGraph.examineWalk(path);
            } else {
                cout << "INVALID WALK\n";
            }
        }
    }

    return 0;
}
