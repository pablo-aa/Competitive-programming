// Disjoint union set
// Operation ~ O(1)
int r[MAXN];
vector<int> qtd(MAXN, 1);

int get(int x) {
  return p[x] = (p[x] == x ? x : get(p[x]));
}

void unite(int a, int b){
  a = get(a);
  b = get(b);

  if(a == b) return;

  if(r[a] == r[b]){
  	p[a] = b;
  	r[b]++;
  	qtd[b]+=qtd[a];
  }else if(r[a] > r[b]){
  	p[b] = a;
  	qtd[a]+=qtd[b];
  }else{
  	p[a] = b;
  	qtd[b]+=qtd[a];
  }
}

// Initializing values in main()
for(int i = 1; i <= n; i++) p[i]=i;
