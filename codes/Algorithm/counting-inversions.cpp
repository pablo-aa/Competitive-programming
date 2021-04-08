// Counting inversions in Array
// O(n log n)
int merge_sort(vector<int>& v){ 
	if(v.size() == 1) return 0;

	vector<int> l, r;

	for(int i = 0; i < v.size()/2; i++) 
		l.push_back(v[i]);
	for(int i = v.size()/2; i < v.size(); i++) 
		r.push_back(v[i]);
	int ans = 0;
	ans += merge_sort(l);
	ans += merge_sort(r);

	l.push_back(1e9);
	r.push_back(1e9);

	int inil = 0, inir = 0;

	for(int i = 0; i < v.size(); i++){
		if(l[inil] <= r[inir]) v[i] = l[inil++];
		else{
			v[i] = r[inir++];
			ans+=l.size()-inil-1;
		}
	}

	return ans;
}