// BFS
// O(n+m)
vector<vector<int> > g(MAX_NODES);
vector<bool> visited(MAX_NODES);
vector<int> dist(MAX_NODES, oo);
queue<int> q;

void bfs(int s){
    q.push(s);
    dist[s] = 0;
    visited[s] = true;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(auto v : g[u]){
            if(not visited[v]){
                dist[v] = dist[u]+1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}