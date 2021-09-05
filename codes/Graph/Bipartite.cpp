// Checking if graph is Bipartite
// O(V+E)

const int MAXN { 100010 };
vector<vector<int> > g(MAXN);
vector<int> color(MAXN);

bool bfs(int s){
	const int NONE=0,B=1,W=2;
	queue<int> q;
	q.push(s);
	color[s]=B;

	while(!q.empty()){
		auto u = q.front(); q.pop();

		for(auto v : g[u]){
			if(color[v] == NONE){
				color[v]=3-color[u];
				q.push(v);
			}else if(color[v]==color[u]){
				return false;
			}
		}

		return true;
	}
}

bool is_bipartite(int n){

    for (int u = 1; u <= n; u++) 
        if (color[u] == NONE && !bfs(u))
            return false;

    return true;
}