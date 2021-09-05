// Augmenting Path Algorithm for Max Cardinality Bipartite Matching
// O(V*E)

// Algorithm to find maximum matches between to set
// of nodes (bipartite graph)

vector<int> match, visited;

int aug(int u){
	if(visited[u]) return 0;
	visited[u]=1;

	for(auto v : g[u]){
		if(match[v]==-1||aug(match[v])){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

// Inside Main()
// Good to try - left v: [0,n-1], right: [n, m-1]
int MCBM=0;
match.assign(V, -1); // V = all vertices(left+right)
for(int i = 0; i < n; i++){ // n = size of left set
	visited.assign(n, 0);
	MCBM+=aug(i);
}