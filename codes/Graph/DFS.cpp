// DFS
// O(n+m)
vector<vector<int> > graph(MAX_NODES);
vector<bool> visited(MAX_NODES);

void dfs(int s){
    if(visited[s]) return;
    visited[s] = true;
    for(auto v : graph[s]){
        dfs(v);
    }
}
