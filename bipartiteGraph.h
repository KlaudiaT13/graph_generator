#pragma once

#include "myGraph.h"

class BipartiteGraph : public MyGraph {
private:
    std::vector<int> first_half;
    std::vector<int> second_half;

public:
    BipartiteGraph(int numberOfNodes, int nodesInFirstHalf);
    bool addEdge(int source, int destination) override;
};
