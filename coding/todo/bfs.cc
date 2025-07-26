# include <vector>
# include <string>
# include <map>
# include <queue>
# include <iostream>

const int mxN = 1e2;
std::map<std::string, int> sdists;

std::map<std::string, int> & dfs(std::vector<std::string> &nodes, std::vector<std::vector<std::string>> &edges, std::string start){
    std::map<std::string, int> mp;
    std::vector<int> adjs[mxN];
    std::queue<int> queue;
    int dists[mxN];
    bool vis[mxN];

    for (int i = 0; i < mxN; ++i)
        vis[i] = false;

    for (int i = 0; i < nodes.size(); ++i){
        mp[nodes[i]] = i;
    }

    for (std::vector<std::string> edge: edges){
        adjs[mp[edge[0]]].push_back(mp[edge[1]]);
        adjs[mp[edge[1]]].push_back(mp[edge[0]]);
    }

    int startIdx = mp[start];
    vis[startIdx] = true;
    dists[startIdx] = 0;
    queue.push(startIdx);

    int v;
    while (queue.size() > 0){
        v = queue.front();
        queue.pop();
        for (int u: adjs[v]){
            if (!vis[u]){
                vis[u] = true;
                dists[u] = dists[v] + 1;
                queue.push(u);
            }
        }
    }

    for (size_t i = 0; i < nodes.size(); ++i)
        sdists[nodes[i]] = dists[i]; 

    return sdists;
}

int main(){
    std::vector<std::string> nodes = {"s", "a", "b", "c", "d", "e"};
    std::vector<std::vector<std::string>> edges = {
        {"s", "a"}, {"s", "b"}, {"a", "c"}, {"b", "c"}, {"b", "d"}, {"c", "d"}, {"c", "e"}, {"e", "d"}
    };
    std::string start = "e";

    sdists = dfs(nodes, edges, start);

    for (auto &sdist: sdists)
        std::cout << sdist.first << "," << sdist.second << std::endl;

    return 0;
}