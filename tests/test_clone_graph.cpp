#include <cstdlib>
#include <external/common/output.hpp>

#include "leetcode/clone_graph.hpp"

void testCloneGraph(std::vector<std::vector<int>> &adj_list)
{
    using common::operator<<;
    leetcode::Graph g;
    leetcode::Solution sol;

    std::cout << "original:\n" << adj_list << "\n";

    leetcode::Node *node_ptr = g.generateNode(adj_list);
    std::cout << "From node:\n" << g.generateAdjList(node_ptr, adj_list.size()) << "\n";

    leetcode::Node *copy_node_ptr = sol.cloneGraph(node_ptr);
    std::cout << "Copy:\n" << g.generateAdjList(copy_node_ptr, adj_list.size()) << "\n";

    g.destruct();

}

int main()
{
    std::vector<std::vector<int>> adj_list;

    adj_list = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};
    testCloneGraph(adj_list);

    adj_list = {{}};
    testCloneGraph(adj_list);

    return EXIT_SUCCESS;
}