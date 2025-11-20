/*
 * CSCE Graph Lab 1 - Individual Work
 * Description: Graph structure supporting adjacency list input, printing, and walk analysis.
 * External Resources Used: NONE
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
private:
    int nodeCount;
    std::vector<std::vector<int>> adjList;

public:
    Graph(int count);

    //Input adjacency list
    void inputConnections();

    //Display the graph
    void showGraph() const;

    //Validate walk (Extra Credit)
    bool checkTheWalkValidity(const std::vector<int>& walkPath) const;

    //Analyze walk properties (Extra Credit)
    void examineWalk(const std::vector<int>& walkPath) const;
};

#endif
