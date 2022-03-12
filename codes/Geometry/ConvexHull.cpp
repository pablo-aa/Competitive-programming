// Convex Hull
// Algorithm: Monotone Chain
// Complexity: O(n) + ordenacao O(nlogn)

#define vp vector<pt>
typedef int T; 

int ccw(pt a, pt b, pt e){ // -1=dir; 0=col; 1=esq; esq = AE está a esquerda de AB
    T tmp = (b-a)^(e-a);
    return (tmp > EPS) - (tmp < -EPS);
}

vector<point> convex_hull(vector<point> p) {
	sort(p.begin(), p.end());

	vector<point> L, U;

	// Lower Hull
	for(auto pp : p){
		while(L.size() >= 2 && esq(L[L.size()-2], L.back(), pp) == -1)
			L.pop_back();
		L.pb(pp);
	}

	reverse(all(p));
	// Upper Hull
	for(auto pp : p){
		while(U.size() >= 2 && esq(U[U.size()-2], U.back(), pp) == -1)
			U.pop_back();
		U.pb(pp);
	}

	L.pop_back();
	L.insert(L.end(), U.begin(), U.end()-1);

	return L;
}
