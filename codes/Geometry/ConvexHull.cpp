// Convex Hull
// Algorithm: Monotone Chain
// Complexity: O(n) + ordenacao O(nlogn)

// Regra mao direita p2->p1 (dedao p cima ? esq : dir || colinear)

int esq(point p1, point p2, point p3){
	cod cross = (p2-p1)^(p3-p1);
	if(cross == 0) return 0;
	else if(cross > 0) return 1;
	return -1;
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
