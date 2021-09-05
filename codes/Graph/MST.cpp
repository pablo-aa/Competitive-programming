// Minimum Spanning tree 
// w/ DSU structure

typedef struct{
	int a, b;
	int w;
} edge;

/* ----- DSU Structure ------*/
int get(int x) {
  return p[x] = (p[x] == x ? x : get(p[x]));
}

void unite(int a, int b){
  a = get(a);
  b = get(b);

  if(r[a] == r[b]) r[a]++;
  if(r[a] > r[b]) p[b] = a;
  else p[a] = b;
}

// Initializing values in main()
for(int i = 1; i <= n; i++) p[i]=i;

/* -------------------------*/

vector<edge> edges;
int total_weight;

void mst(){
	// sort edges
	for(auto e : edges){
		if(get(e.a) != get(e.b)){
			unite(e.a, e.b);
			total_weight+=e.w;
		}
	}
}
