// BFS
// O(V+E)

const int MAXN { 100010 };

vector<vector<int> > g(MAXN);
vector<bool> visited(MAXN);
vector<int> dist(MAXN, oo);
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