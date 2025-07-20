#include "BipartiteGraph.h"

BipartiteGraph::BipartiteGraph(int numberOfNodes, int nodesInFirstHalf)
    : MyGraph(numberOfNodes)
{
    first_half.reserve(nodesInFirstHalf);
    second_half.reserve(numberOfNodes - nodesInFirstHalf);
    for (int i = 0; i < numberOfNodes; ++i) {
        if (i < nodesInFirstHalf)
            first_half.emplace_back(i);
        else
            second_half.emplace_back(i);
    }
}

bool BipartiteGraph::addEdge(int source, int destination) {
    if ((source < first_half.size() && destination >= first_half.size()) ||
        (destination < first_half.size() && source >= first_half.size())) {
        adj_matrix[source][destination] = 1;
        adj_matrix[destination][source] = 1;
        return true;
        }
    return false;
}
