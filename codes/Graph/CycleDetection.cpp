// Existency of Cycle in a Graph

// 1. Better to use when path is important
// O(V+E)
const int MAXN { 100010 };
vector<int> visited(MAXN, 0);
vector<vector<int> > g(MAXN);

bool dfs_cycle(int u){
	if(visited[u]) return false;

	visited[u] = true;

	for(auto v : g[u]){
		if(visited[v] && v != u) return true;
		if(dfs_cycle(v)) return true;
	}
	return false;
}

bool has_cycle(int n){
	visited.reset();

	for(int u = 1; u <= n; u++)
		if(!visited[u] && dfs(u))
			return true;

	return false;
}

// 2. Better when only detect cycle is important
// Only for undirected graphs
// When E>=V, a cycle exists

void dfs(int u, function<void(int)> process){
    if (visited[u])
        return;

    visited[u] = true;

    process(u);

    for (auto v : adj[u])
        dfs(v, process);
}

bool has_cycle(int N) {
    visited.reset();

    for (int u = 1; u <= N; ++u) 
        if (not visited[u])
        {
            vector<int> cs;
            size_t edges = 0;

            dfs(u, [&](int u) {
                cs.push_back(u); 

                for (const auto& v : adj[u])
                    edges += (visited[v] ? 0 : 1);
            });

            if (edges >= cs.size()) return true;
        }

    return false;
}
