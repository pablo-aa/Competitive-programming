// Merge Sort
// O(n log n)
void merge_sort(vector<int>& v){
	if(v.size() == 1) return;

	vector<int> l, r;

	for(int i = 0; i < v.size()/2; i++) 
	    l.push_back(v[i]);
	for(int i = v.size()/2; i < v.size(); i++) 
	    r.push_back(v[i]);

	merge_sort(l);
	merge_sort(r);

	l.push_back(INF);
	r.push_back(INF);

	int inil = 0, inir = 0;

	for(int i = 0; i < v.size(); i++){
		if(l[inil] < r[inir]) v[i] = l[inil++];
		else v[i] = r[inir++];
	}

	return;
}
