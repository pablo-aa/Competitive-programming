#include <bits/stdc++.h>
#define pb push_back
#define ll long long int
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++) 
using namespace std;

// End Template //

#define MAXN 10001

int n;
int tab[MAXN];
bool foi[MAXN];
vector<ll> v;

ll dp(int i){
	if(i == 0) return v[0];
	if(foi[i]) return tab[i];
	foi[i]= true;
	return tab[i] = max(v[i], dp(i-1) + v[i]);
}
 
int main(){
    sws;

 	cin >> n;

 	v.assign(n, 0);
 	forn(i, n) cin >> v[i];

 	ll ans = 0;
 	forn(i, n) ans = max(ans, dp(i));

 	cout << ans << endl;

    return 0;
}
 
