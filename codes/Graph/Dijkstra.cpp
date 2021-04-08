// Dijkstra
// O(n + m log m)
#define INF 1e9+10
vector<pair<int, int>> adj[MAXN];
vector<int> dist;
vector<bool> visited;
priority_queue<pair<int,int>> q;

void Dijkstra(int n, int start){
    for(int i = 0; i <= n; i++){
        dist.push_back(INF);
        visited.push_back(false);
    }
    dist[start] = 0;
    q.push(make_pair(0, start));
    while(!q.empty()){
        int a = q.top().second; q.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto u : adj[a]){
            int b = u.first, w = u.second;
            if(dist[a]+w < dist[b]){
                dist[b] = dist[a]+w;
                q.push({-dist[b], b});
            }
        }
    }
}
