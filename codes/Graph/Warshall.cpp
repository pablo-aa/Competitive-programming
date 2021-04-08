// Floyd - Warshall
// O(n^3)
#define INF 1e9+10

int adj[MAXN][MAXN];
int distances[MAXN][MAXN];

void Warshall(int n, int start){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) distances[i][j] = 0;
            else if (adj[i][j]) distances[i][j] = adj[i][j];
            else distances[i][j] = INF;
        }
    }
    for (int z = 1; z <= n; z++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                distances[i][j] = min(distances[i][j],distances[i][z] + distances[z][j]);
            } 
        }
    }
}