#pragma once
#include <vector>
#include <boost/graph/adjacency_list.hpp>

// Define Boost graph type
typedef boost::adjacency_list<
    boost::vecS, boost::vecS, boost::undirectedS,
    boost::no_property,
    boost::property<boost::edge_index_t, int>
> GraphBoost;

class MyGraph {
private:
    int numberOfNodes;

public:
    std::vector<std::vector<int>> adj_matrix;

    explicit MyGraph(int numberOfNodes);

    virtual bool addEdge(int source, int destination);
    bool removeEdge(int source, int destination);
    GraphBoost convertToBoostGraph(const std::vector<std::vector<int>>& adj_matrix);
    bool isPlanar();
};