#include <iostream>
#include <vector>
#include <list>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/boyer_myrvold_planar_test.hpp>
#include <random>
#include "myGraph.h"
#include "BipartiteGraph.h"
#include "CompleteGraph.h"


using namespace std;
using namespace boost;


std::vector<std::vector<int>> generateAdjMatrix(
    int n,
    double edge_prob = 0.3,
    bool directed = false,
    bool allow_self_loops = false
) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_real_distribution<> dist(0.0, 1.0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!allow_self_loops && i == j)
                continue;

            if (dist(rng) < edge_prob) {
                matrix[i][j] = 1;
                if (!directed)
                    matrix[j][i] = 1;
            }
        }
    }

    return matrix;
}

template <typename T>
void printMatrix(vector<vector<T> > matrix) {
    for (const auto& row : matrix) {
        for (int val : row)
            std::cout << val << " ";
        std::cout << "\n";
    }
}


// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.
    int n = 5;
    auto matrix = generateAdjMatrix(n, 0.5, false);
    printMatrix(matrix);
    MyGraph graph(n);
    cout <<"is graph planar?: "<< graph.isPlanar()<< endl;
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}