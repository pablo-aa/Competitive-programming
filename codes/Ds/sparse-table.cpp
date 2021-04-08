// Sparse-Table
// O(log n)
const int logn = 22; // max log

int logv[MAX];
// Pre comp log values
void make_log(){
	logv[1] = 0;
	for(int i = 2; i <= MAX; i++)
		logv[i] = logv[i/2]+1;
}

struct Sparse {
	vector<vector<int> > st;

	Sparse(vector<int>& v) {
		int n = v.size();
		st.assign(n, vector<int>(logn, 0));
		// Unitary values st[i][0] = v[i, i+2^0] = v[i]
		for(int i = 0; i < n; i++){
			st[i][0] = v[i];
		}
		// Constructing Sparse Table in O(log n)
		for(int k = 1; k < logn; k++){
			for(int i = 0; i < n; i++){
				if(i + (1 << k)-1 >= n)
					continue;
				int prox = i + (1 << (k-1));
				st[i][k] = min(st[i][k-1], st[prox][k-1]);
			}
		}
	}

	int f(int a, int b){
		// Can be: min, max, gcd
		// f must have idempotent property
		return min(a, b);
	}
	// Queries in O(1)
	int query(int l, int r){
		int size = r-l+1;
		int k = logv[size];
		// cat jump for queries in O(1)
		int res = f(st[l][k], st[r - ((1 << k)-1)][k]);
		return res;
	}
};