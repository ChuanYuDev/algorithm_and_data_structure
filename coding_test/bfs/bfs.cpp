# include <vector>
# include <string>
# include <map>
# include <queue>
# include <iostream>


std::map<std::string, int> undirected_graph_bfs(std::vector<std::string> &nodes, std::vector<std::vector<std::string>> &edges, std::string start){
    std::map<std::string, int> node_name_shortest_distance;
    std::map<std::string, int> node_name_to_number_map;

    int node_num = nodes.size();

    std::vector<int> *adjacency_list = new std::vector<int>[node_num];
    std::queue<int> queue;

    int *shortest_distance = new int[node_num];
    bool *visited = new bool[node_num];

    for (int i = 0; i < node_num; ++i)
        visited[i] = false;

    for (int i = 0; i < node_num; ++i){
        node_name_to_number_map[nodes[i]] = i;
    }

    for (std::vector<std::string> edge: edges)
    {
        adjacency_list[node_name_to_number_map[edge[0]]].push_back(node_name_to_number_map[edge[1]]);
        adjacency_list[node_name_to_number_map[edge[1]]].push_back(node_name_to_number_map[edge[0]]);
    }

    int startIdx = node_name_to_number_map[start];
    visited[startIdx] = true;
    shortest_distance[startIdx] = 0;
    queue.push(startIdx);

    int v;
    while (queue.size() > 0){
        v = queue.front();
        queue.pop();
        for (int u: adjacency_list[v])
        {
            if (!visited[u]){
                visited[u] = true;
                shortest_distance[u] = shortest_distance[v] + 1;
                queue.push(u);
            }
        }
    }

    for (size_t i = 0; i < nodes.size(); ++i)
        node_name_shortest_distance[nodes[i]] = shortest_distance[i]; 
    
    delete [] adjacency_list;
    delete [] shortest_distance;
    delete [] visited;

    return node_name_shortest_distance;
}

int main()
{
    std::vector<std::string> nodes = {"s", "a", "b", "c", "d", "e"};
    std::vector<std::vector<std::string>> edges = 
    {
        {"s", "a"}, {"s", "b"}, {"a", "c"}, {"b", "c"}, {"b", "d"}, {"c", "d"}, {"c", "e"}, {"e", "d"}
    };
    std::string start = "e";

    std::map<std::string, int> node_name_shortest_distance = undirected_graph_bfs(nodes, edges, start);

    for (auto &sdist: node_name_shortest_distance)
        std::cout << sdist.first << "," << sdist.second << std::endl;

    return 0;
}