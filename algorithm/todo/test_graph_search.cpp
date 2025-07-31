#include "dsaa/graph_search.hpp"

int main()
{
    std::vector<std::vector<int>> adj_list = {{1, 2}, {0, 3}, {0, 3}, {1, 4, 5}, {2, 3, 5}, {3, 4}};

    std::cout << "bfs:\n";
    dsaa::bfs(adj_list, 0);

    std::cout << "\ndfs stack:\n";
    dsaa::dfsStack(adj_list, 0);

    std::cout << "\ndfs recursive:\n";
    dsaa::dfsRecursive(adj_list, 0);

    std::cout << std::endl;

    return EXIT_SUCCESS;
}