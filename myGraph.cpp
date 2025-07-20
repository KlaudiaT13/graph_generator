#include "myGraph.h"
#include <iostream>
#include <stdexcept>
#include <boost/graph/make_biconnected_planar.hpp>
#include <boost/graph/boyer_myrvold_planar_test.hpp>

using namespace std;
using namespace boost;

MyGraph::MyGraph(int numberOfNodes)
    : numberOfNodes(numberOfNodes), adj_matrix(numberOfNodes, vector<int>(numberOfNodes, 0)) {}

bool MyGraph::addEdge(int source, int destination) {
    adj_matrix[source][destination] = 1;
    adj_matrix[destination][source] = 1;
    return true;
}

bool MyGraph::removeEdge(int source, int destination) {
    adj_matrix[source][destination] = 0;
    adj_matrix[destination][source] = 0;
    return true;
}

GraphBoost MyGraph::convertToBoostGraph(const std::vector<std::vector<int>>& matrix) {
    size_t n = matrix.size();
    for (const auto& row : matrix) {
        if (row.size() != n)
            throw std::runtime_error("Adjacency matrix must be square.");
    }

    GraphBoost g(n);
    for (size_t i = 0; i < n; ++i)
        for (size_t j = i + 1; j < n; ++j)
            if (matrix[i][j])
                add_edge(i, j, g);

    auto edge_index_map = get(boost::edge_index, g);
    int index = 0;
    for (auto e : boost::make_iterator_range(edges(g))) {
        put(edge_index_map, e, index++);
    }

    return g;
}

bool MyGraph::isPlanar() {
    GraphBoost g = convertToBoostGraph(this->adj_matrix);

    auto edge_index_map = get(boost::edge_index, g);
    int index = 0;
    for (auto e : boost::make_iterator_range(edges(g))) {
        put(edge_index_map, e, index++);
    }

    bool is_planar = boyer_myrvold_planarity_test(g);
    std::cout << (is_planar ? "Planar" : "Not planar") << std::endl;
    return is_planar;
}
