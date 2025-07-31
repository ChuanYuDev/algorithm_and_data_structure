#ifndef DSAA_KAHN_TOPOLOGICAL_SORTING_HPP_
#define DSAA_KAHN_TOPOLOGICAL_SORTING_HPP_

#include <vector>
#include <queue>
#include <cassert>

namespace dsaa
{
    bool kahnTopologicalSorting(const std::vector<std::vector<int>> &adjs, std::vector<int> &sort)
    {
        const auto vertex_num = adjs.size();

        std::vector<int> in_degrees(vertex_num);

        for (auto &adj: adjs)
        {
            for (auto &adj_vertex: adj)
                in_degrees[adj_vertex]++;
        }

        std::queue<int> queue;

        for (std::size_t i = 0; i < vertex_num; ++i)
        {
            if (in_degrees[i] == 0)
                queue.push(i);
        }

        int top = 0;

        while (!queue.empty())
        {
            top = queue.front();
            queue.pop();
            sort.push_back(top);

            for (auto &adj_vertex: adjs[top])
            {
                --in_degrees[adj_vertex];

                if (in_degrees[adj_vertex] == 0)
                    queue.push(adj_vertex);
            }
        }

        return (vertex_num == sort.size())? true: false;
    }
} // namespace dsaa

#endif // DSAA_KAHN_TOPOLOGICAL_SORTING_HPP_