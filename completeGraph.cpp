#include "CompleteGraph.h"

CompleteGraph::CompleteGraph(int numberOfNodes)
    : MyGraph(numberOfNodes) {
    for (int i = 0; i < numberOfNodes; ++i) {
        for (int j = i + 1; j < numberOfNodes; ++j) {
            MyGraph::addEdge(i, j);
        }
    }
}

