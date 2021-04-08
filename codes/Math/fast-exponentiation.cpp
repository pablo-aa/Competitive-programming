// Fast Exponentiation
// O(log n)
ll fexp(ll b, ll e){
	if(e == 0){
		return 1;
	}
	ll resp = fexp(b, e/2)%MOD;
	resp = (resp*resp)%MOD;
	if(e%2) resp = (b*resp)%MOD;

	return resp;
}