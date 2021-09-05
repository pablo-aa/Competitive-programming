// Bellman Ford - Min distance

// O(V*E)
// Min dist from a start node
// Can be aplied to negative weights

using edge = tuple<int, int, int>;

vector<int> bellman_ford(int s, int N, const vector<edge>& edges){
    const int oo { 1000000010 };

    vector<int> dist(N + 1, oo);
    dist[s] = 0;

    for (int i = 1; i <= N - 1; i++)
        for (auto [u, v, w] : edges)
            if (dist[u] < oo and dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                // pred[v]=u to find path
            }

    return dist;
}

// Identifying negative Cycle
bool has_negative_cycle(int s, int N, const vector<edge>& edges){
    const int oo { 1000000010 };

    vector<int> dist(N + 1, oo);
    dist[s] = 0;

    for (int i = 1; i <= N - 1; i++)
        for (auto [u, v, w] : edges)
            if (dist[u] < oo and dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;

    // If after all rounds, exists a better answer - Negative cycle found
    for (auto [u, v, w] : edges)
        if (dist[u] < oo and dist[v] > dist[u] + w)
            return true;

    return false;
}

