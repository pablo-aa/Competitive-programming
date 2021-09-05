// Algorithm to get bridges in a graph

using edge = pair<int, int>;

const int MAX { 100010 }; 
int dfs_num[MAX], dfs_low[MAX];
vector<vector<int> > adj;

void dfs_bridge(int u, int p, int& next, vector<edge>& bridges){
    
    dfs_low[u] = dfs_num[u] = next++;

    for (auto v : adj[u])
        if (not dfs_num[v]) {

            dfs_bridge(v, u, next, bridges);

            if (dfs_low[v] > dfs_num[u])
                bridges.emplace_back(u, v);

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != p)
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
}

vector<edge> bridges(int n){

    memset(dfs_num, 0, (n + 1)*sizeof(int));
    memset(dfs_low, 0, (n + 1)*sizeof(int));

    vector<edge> bridges;

    for (int u = 1, next = 1; u <= n; ++u)
        if (not dfs_num[u])
            dfs_bridge(u, u, next, bridges);
    
    return bridges;
}