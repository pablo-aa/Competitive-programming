// You have n coins {c1, ..., cn}
// Find min quantity of coins to sum K
// O(n.c)
int dp(int acc){ // Recursive version
	if(acc < 0) return oo;
	if(acc == 0) return 0;
	
	if(memo[acc] != -1) return memo[acc];

	int best = oo;

	for(auto c : coins){
		best = min(best, dp(acc-c)+1);
	}

	return memo[acc] = best;
}

int dp(){ // Iterative version
	memo[0] = 0
	for(int i = 1; i <= n; i++){
		memo[i] = oo;
		for(auto c : coins){
			if(i-c >= 0)
				memo[i] = min(memo[i], memo[i-c]+1);
		}
	}
}
