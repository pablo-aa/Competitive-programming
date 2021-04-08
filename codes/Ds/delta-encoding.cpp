// Delta encoding
// O (n)

for(int i = 0; i < queries; i++){
	int l, r, x;
	cin >> l >> r >> x;
	delta[l]+=x;
	delta[r+1]-=x;
}
int acc = 0;
for(int i = 0; i < v.size(); i++){
	acc+=delta[i];
	v[i]+=acc;
}
