/*
 * CSCE Graph Lab 1 - Individual Work
 * Description: Implements graph logic using adjacency list and walk analysis.
 * External Resources Used: NONE
 */

#include "Graph.h"
#include <iostream>
#include <set>
#include <utility>

using namespace std;

Graph::Graph(int count) : nodeCount(count) {
    adjList.resize(nodeCount);
}

void Graph::inputConnections() {
    for (int index = 0; index < nodeCount; ++index) {
        cout << "Enter neighbors count for the node " << index << " (-1 to finish):\n";
        int linkedNode;
        while (cin >> linkedNode && linkedNode != -1) {
            if (linkedNode >= 0 && linkedNode < nodeCount) {
                adjList[index].push_back(linkedNode);
            } else {
                cout << "Invalid node. Try again.\n";
            }
        }
    }
}

void Graph::showGraph() const {
    for (int idx = 0; idx < nodeCount; ++idx) {
        cout << idx << ": ";
        for (const int& neighbor : adjList[idx]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

bool Graph::checkTheWalkValidity(const vector<int>& walkPath) const {
    for (size_t i = 0; i + 1 < walkPath.size(); ++i) {
        int from = walkPath[i];
        int to = walkPath[i + 1];
        bool connected = false;

        for (const int& neighbor : adjList[from]) {
            if (neighbor == to) {
                connected = true;
                break;
            }
        }

        if (!connected) return false;
    }
    return true;
}

void Graph::examineWalk(const vector<int>& walkPath) const {
    if (walkPath.size() < 2) {
        cout << "Walk is too short to evaluate.\n";
        return;
    }

    bool isOpen = walkPath.front() != walkPath.back();
    bool isTrail = true;
    bool isPath = true;

    set<pair<int, int>> visitedEdges;
    set<int> visitedNodes;

    for (size_t i = 0; i + 1 < walkPath.size(); ++i) {
        int a = walkPath[i];
        int b = walkPath[i + 1];

        if (visitedEdges.count({a, b}) || visitedEdges.count({b, a})) {
            isTrail = false;
        }
        visitedEdges.insert({a, b});

        if (visitedNodes.count(b)) {
            isPath = false;
        }
        visitedNodes.insert(a);
    }

    bool isCircuit = !isOpen && isTrail;
    bool isCycle = !isOpen && isPath;

    cout << "Walk sequence is <";
    for (size_t i = 0; i < walkPath.size(); ++i) {
        cout << walkPath[i];
        if (i != walkPath.size() - 1) cout << ", ";
    }
    cout << "> properties:\n";

    cout << (isOpen ? "OPEN\n" : "CLOSED\n");
    if (isTrail) cout << "TRAIL\n";
    if (isPath) cout << "PATH\n";
    if (isCircuit) cout << "CIRCUIT\n";
    if (isCycle) cout << "CYCLE\n";
}
