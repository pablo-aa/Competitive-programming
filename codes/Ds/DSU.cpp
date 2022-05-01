// Disjoint union set
// Operation ~ O(1)
struct DSU {
    int n = 0;
    vector<int> p;
    vector<int> r;

    DSU(int nn){
        n = nn;
        r.assign(n + 5, 1);
        p.assign(n + 5, 0);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x){
        return p[x] = (p[x] == x ? x : find(p[x]));
    }

    void join(int a, int b){
        a = find(a); b = find(b);
        if(a == b) return;
        if(r[a] < r[b]) swap(a, b);
        p[b] = a;
        r[a] += r[b];
    }   
};

// Initializing values in main()
// DSU(n+1)
