#ifndef LEETCODE_CLONE_GRAPH_HPP_
#define LEETCODE_CLONE_GRAPH_HPP_

#include <vector>
#include <queue>
#include <map>

namespace leetcode
{

// Definition for a Node.
class Node
{
public:
    int val;
    std::vector<Node*> neighbors;

    Node()
    {
        val = 0;
        neighbors = std::vector<Node*>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node*>();
    }

    Node(int _val, std::vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node * cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        std::vector<bool> visited(101, false);
        std::queue<Node *> q;
        std::map<int, Node *> val_clone_node_map;

        visited[node->val] = true;
        val_clone_node_map[node->val] = new Node(node->val);
        q.push(node);

        Node *node_ptr = nullptr, *clone_node_ptr = nullptr;

        while (!q.empty())
        {
            node_ptr = q.front(); 
            clone_node_ptr = val_clone_node_map[node_ptr->val];

            q.pop();

            for (auto neighbor: node_ptr->neighbors)
            {
                if (!visited[neighbor->val])
                {
                    visited[neighbor->val] = true;
                    val_clone_node_map[neighbor->val] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                clone_node_ptr->neighbors.push_back(val_clone_node_map[neighbor->val]);
            }
        }

        return val_clone_node_map[node->val];
    }
};

class Graph
{
private:
    std::vector<Node *> nodes;

public:
    Node * generateNode(std::vector<std::vector<int>> adj_list)
    {
        const auto v_num = adj_list.size();
        std::map<int, Node *> val_node_map;

        for (std::size_t i = 0; i < v_num; ++i)
        {
            val_node_map[i + 1] = new Node(i + 1);
        }

        for (std::size_t i = 0; i < v_num; ++i)
        {
            for (auto adj: adj_list[i])
            {
                val_node_map[i + 1]->neighbors.push_back(val_node_map[adj]);
            }
        }

        return val_node_map[1];
    }

    std::vector<std::vector<int>> generateAdjList(Node *node, int node_num)
    {
        std::vector<std::vector<int>> adj_list(node_num);

        std::vector<bool> visited(node_num + 1, false);
        std::queue<Node *> q;

        visited[node->val] = true;
        q.push(node);

        Node *node_ptr = nullptr;

        while (!q.empty())
        {
            node_ptr = q.front();
            nodes.push_back(node_ptr);
            auto &adj = adj_list[node_ptr->val - 1];
            q.pop();

            for (auto neighbor: node_ptr->neighbors)
            {
                if (!visited[neighbor->val])
                {
                    visited[neighbor->val] = true;
                    q.push(neighbor);
                }

                adj.push_back(neighbor->val);
            }
        }

        return adj_list;
    }

    void destruct()
    {
        for (auto node: nodes)
            delete node;
    }
};

} // namespace leetcode

#endif // LEETCODE_CLONE_GRAPH_HPP_ 