// Z-function
// O(n)

// Return array z(n) that each value z[i] tells the
// longest subsequence from i that is prefix of string s.

// Pattern Matching = z-func(s1$s2) acha s1 em s2.

vector<ll> z_algo(const string &s){   
    ll n = s.size();
    ll L = 0, R = 0;
    vector<ll> z(n, 0);
    for(ll i = 1; i < n; i++){
        if(i <= R)
            z[i] = min(z[i-L], R - i + 1);
        while(z[i]+i < n and s[ z[i]+i ] == s[ z[i] ])
            z[i]++;
        if(i+z[i]-1 > R){
            L = i;
            R = i + z[i] - 1;
        }
    }
    z[0]=n;
    return z;
}