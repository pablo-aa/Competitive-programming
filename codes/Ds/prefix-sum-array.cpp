// Preffix sum 1D
// O(n)
int v[MAXN];
int psum[MAXN];

int create_psum(){
	int acc = 0;
	for(int i = 0; i < v.size(); i++){
		acc+=v[i];
		psum[i] = acc;
	}
}

int query(int l, int r){
	return l == 0 ? psum[r] : psum[r]-psum[l-1];
}
