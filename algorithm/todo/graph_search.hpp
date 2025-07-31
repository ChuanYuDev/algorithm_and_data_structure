#ifndef DSAA_GRAPH_SEARCH_HPP_
#define DSAA_GRAPH_SEARCH_HPP_

#include <vector>
#include <queue>
#include <stack>
#include <iostream>

namespace dsaa
{

void bfs(const std::vector<std::vector<int>> &adj_list, int s)
{
    std::vector<bool> visited(adj_list.size(), false);
    std::queue<int> q;
    int v = 0;

    visited[s] = true;
    std::cout << s << " ";
    q.push(s);

    while (!q.empty())
    {
        v = q.front();
        q.pop();

        for (auto w: adj_list[v])
        {
            if (!visited[w])
            {
                visited[w] = true;
                std::cout << w << " ";
                q.push(w);
            }
        }
    }
}

void dfsStack(const std::vector<std::vector<int>> &adj_list, int s)
{
    std::vector<bool> visited(adj_list.size(), false);
    std::stack<int> st;
    int v = 0;

    st.push(s);

    while (!st.empty())
    {
        v = st.top();
        st.pop();

        if (!visited[v])
        {
            visited[v] = true;
            std::cout << v << " ";

            for (auto w: adj_list[v])
            {
                if (!visited[w])
                    st.push(w);
            }
        }
    }
}

void dfsRecursiveImpl(const std::vector<std::vector<int>> &adj_list, std::vector<bool> &visited, int s)
{
    visited[s] = true;
    std::cout << s << " ";

    for (auto v: adj_list[s])
    {
        if (!visited[v])
            dfsRecursiveImpl(adj_list, visited, v);
    }
}

void dfsRecursive(const std::vector<std::vector<int>> &adj_list, int s)
{
    std::vector<bool> visited(adj_list.size(), false);

    dfsRecursiveImpl(adj_list, visited, s);
}

} // namespace dsaa

#endif // DSAA_GRAPH_SEARCH_HPP_