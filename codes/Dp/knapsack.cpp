// Knapsack problem
// O(n.w)
int valor[MAXN], peso[MAXN], memo[MAXN];

ll solve(int i, int w){ // Recursive version
    if(i <= 0 || w <= 0) return 0;
    if(memo[i][w] != -1) return memo[i][w];
    ll pegar=-1e9;
    
    if(peso[i] <= w){
        pegar = solve(i-1,w-peso[i])+valor[i];
    }

    ll naopegar = solve(i-1,w);
    
    memo[i][w] = max(pegar,naopegar);
    
    return memo[i][w];
}

int dp[MAXN][MAXN], valor[MAXN], peso[MAXN];
int solve(int n, w){  // Iterative version
// n objects | max weight
    for(int i = 0; i <= n; i++)
        for(int j=0; j <= w;j++)
            dp[i][j] = 0;
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            if(i == 0 || j == 0) return dp[i][j];
            else if(peso[i-1] <= j)
                dp[i][j] = max(dp[i-1][j-peso[i-1]]+valor[i-1],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}

int val[MAX], wt[MAX], dp[MAX]; // Optimization for space
int solve(int n, int W){
    for(int i=0; i < n; i++)
        for(int j=W; j>=wt[i]; j--) 
            dp[j] = max(dp[j],dp[j-wt[i]]+val[i]); 
    return dp[W];
}

