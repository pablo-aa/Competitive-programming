// Knapsack (unlimited objects)
// O(n.w)

int w, n;
int c[MAXN], v[MAXN], dp[MAXN];

int unbounded_knapsack(){
	
    for(int i=0;i<=w;i++)
        for(int j=0;j<n;j++)
            if(c[j] <= i)
                dp[i] = max(dp[i], dp[i-c[j]] + v[j]);

    return dp[w];
}