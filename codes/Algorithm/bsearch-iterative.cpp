// Binary search in iterative questions 
// O(log n)
bool query(int mid, int x){
	cout << mid << endl;
	cout.flush();

	int ans;
	cin >> ans;
	return ans == x;
}

int solve(int x){
	int l = 1, r = n;
	int res = -1;

	while(l <= r){
		int mid = (l+r)/2;
		if(query(mid, x)){
			res = mid;
			l = mid+1;
		}else{
			r = m-1;
		}	
	}

	return res;
}