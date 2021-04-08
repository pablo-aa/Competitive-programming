// Disjoint union set
// O(alfa(n)) - log n
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
