# include <vector>
# include <stack>
# include <iostream>
# include <map>

const int mxN = 1e2;
std::map<int, int> mp;
std::vector<int> adjs[mxN], rev_adjs[mxN];
std::stack<int> st;
int vis1[mxN], vis2[mxN];
int leaders[mxN];

void dfs1(int start){
    vis1[start] = true;

    for (int rev_adj: rev_adjs[start]){
        if (!vis1[rev_adj])
            dfs1(rev_adj);
    }

    st.push(start);
}

void dfs2(int leader, int start){
    vis2[start] = true;
    leaders[start] = leader;

    for (int adj: adjs[start]){
        if (!vis2[adj])
            dfs2(leader, adj);
    }
}

void kosaraju(std::vector<int> &nodes, std::vector<std::vector<int>> &edges){
    for (int i = 0; i < nodes.size(); ++i){
        mp[nodes[i]] = i;
    }

    std::vector<int> edge;
    int u, v;
    for (int i = 0; i < edges.size(); ++i){
        u = mp[edges[i][0]];
        v = mp[edges[i][1]];
        adjs[u].push_back(v);
        rev_adjs[v].push_back(u);
    }

    for (int i = 0; i < nodes.size(); ++i){
        vis1[i] = false;
        vis2[i] = false;
    }
    
    dfs1(0);

    while(st.size()){
        u = st.top();
        // std::cout << nodes[u] << " ";
        st.pop();

        if (!vis2[u]){
            dfs2(u, u);
        }
    }
}

int main(){
    std::vector<int> nodes = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<std::vector<int>> edges = {
        {1, 4}, {7, 1}, {4, 7}, {9, 7}, {6, 9}, {9, 3}, {3, 6}, {8, 6}, {2, 8}, {8, 5}, {5, 2}
    };
    kosaraju(nodes, edges);

    for (int i = 0; i < nodes.size(); ++i)
        std::cout << nodes[i] << " <- " << nodes[leaders[i]] << std::endl;

    return 0;
}