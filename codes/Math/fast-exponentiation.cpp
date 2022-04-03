// Fast Exponentiation
// O(log n)

ll fexp(ll b, ll e, ll mod) {
    ll res = 1;
    b %= mod;
    while(e){ 
        if(e & 1LL)
            res = (res * b) % mod;
        e = e >> 1LL;
        b = (b * b) % mod;
    }
    return res;
}

// ll fexp(ll b, ll e){
// 	if(e == 0){
// 		return 1;
// 	}
// 	ll resp = fexp(b, e/2)%MOD;
// 	resp = (resp*resp)%MOD;
// 	if(e%2) resp = (b*resp)%MOD;

// 	return resp;
// }