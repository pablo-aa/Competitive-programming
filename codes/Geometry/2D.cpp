// 2D Geometry lib
// Good questions: Corner cases? Imprecisions?

typedef ld T; 
bool eq(T a, T b){ return fabs(a - b) <= EPS; }

// typedef int T; // or int
// bool eq(T a, T b){ return (a==b); }

#define sq(x) ((x)*(x))
#define rad_to_deg(x) (180/PI)*x
#define vp vector<pt>

const ld DINF = 1e18;

struct pt{
    T x, y;

    pt(T x=0, T y=0): x(x), y(y){};

    pt operator+(const pt &o) const{ return {x+o.x, y+o.y}; }
    pt operator-(const pt &o) const{ return {x-o.x, y-o.y}; }
    pt operator*(T t) const{ return {x*t, y*t};}
    pt operator/(T t) const{return {x/t, y/t};}
    T operator*(const pt &o) const{ return x * o.x + y * o.y; }
    T operator^(const pt &o) const{ return x * o.y - y * o.x; }

    bool operator<(const pt &o) const{ if(!eq(x, o.x)) return x < o.x; return y < o.y; }
    bool operator==(const pt &o) const{ return eq(x, o.x) and eq(y, o.y); }
};


//\ PONTO E VETOR /\\

bool nulo(pt p){ return (eq(p.x, 0) && eq(p.y, 0));} // confere se = nulo

ld dist(pt p, pt q){ return hypot(p.y - q.y, p.x - q.x); } // distancia

ld dist2(pt p, pt q){ return sq(p.y - q.y) + sq(p.x - q.x); } // distancia*distancia

ld norm(pt p){ return dist(pt(0, 0), p); } // norma do vetor

ld sArea(pt p, pt q, pt r) { // 
    return ((q-p)^(r-q))/2;
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
    return eq(sArea(p, q, r), 0);
}

ld angle(pt p){ // angle of a vector
    ld ang = atan2(p.y, p.x);
    if (ang < 0) ang += 2*PI;
    return ang;
}

ld angle(pt p, pt q){ // angle between two vectors
    ld ang = p*q / norm(p) / norm(q);
    return acos(max(min(ang, (ld)1), (ld)-1));
}

int ccw(pt a, pt b, pt e){ // -1=dir; 0=col; 1=esq; esq = AE está a esquerda de AB
    T tmp = (b-a)^(e-a);
    return (tmp > EPS) - (tmp < -EPS);
}

pt rotccw(pt p, ld a){ // rotacionar ccw
    // a = PI*a/180; // graus
    return pt((p.x*cos(a)-p.y*sin(a)), (p.y*cos(a)+p.x*sin(a)));
}

pt rot90cw(pt p) { return pt(p.y, -p.x); };

pt rot90ccw(pt p) { return pt(-p.y, p.x); };

ld proj(pt a, pt b){ // a sobre b
    return a*b/norm(b);
}

int paral(pt u, pt v) { // se u e v sao paralelos
    if (!eq(u^v, 0)) return 0;
    if ((u.x > EPS) == (v.x > EPS) && (u.y > EPS) == (v.y > EPS))
        return 1;
    return -1;
}

pt mirror(pt m1, pt m2, pt p){
    // mirror pt p around segment m1m2
    pt seg = m2-m1;
    ld t0 = ((p-m1)*seg) / (seg*seg);
    pt ort = m1 + seg*t0;
    pt pm = ort-(p-ort);
    return pm;
}

pt center(vp &A){ // center of pts
    pt c = pt();
    int len = A.size();
    for(int i=0;i<len;i++)
        c=c+A[i];
    return c/len;
}

bool simetric(vector<pt> &a){ // ordered - check simetric pt
    int n = a.size(); // . . . . ok / . .  .. !ok
    pt c = center(a);
    if(n&1) return false;
    for(int i=0;i<n/2;i++)
        if(!col(a[i], a[i+n/2], c))
            return false;
    return true;
}

//\ LINE /\\

struct line{ // line or line segment

    T a, b, c;
    pt p1, p2; // ax + by + c = 0 -> y = ((-a/b)x - (c/b))
    line(pt p1, pt p2): p1(p1), p2(p2){
        a = p1.y-p2.y; b = p2.x-p1.x; c = -(a*p1.x + b*p1.y);
    }

    line(T a, T b, T c): a(a), b(b), c(c){
        if(b == 0){ p1 = pt(0, -c/a); p2 = pt(0, -c/a); }else{
            p1 = pt(1, (-c-a*1)/b);
            p2 = pt(0, -c/b);
        }
    }

    T eval(pt p){ // value of {x,y} on line
        return a*p.x+b*p.y+c;
    }

    bool insideLine(pt p){ // check if pt is inside line
        return eq(eval(p), 0);
    }

    bool insideSeg(pt p){ // check if pt is inside line seg
        return (insideLine(p) &&
                    min(p1.x, p2.x)<=p.x && p.x<=max(p1.x, p2.x) &&
                    min(p1.y, p2.y)<=p.y && p.y<=max(p1.y, p2.y));
    }

    pt normal(){ // normal vector 
        return pt(a, b);
    }

};


vp intersecLine(line l1, line l2){ // pt of two line intersec
    ld det = l1.a*l2.b - l1.b*l2.a;
    if(det==0) return {};
    ld x = (l1.b*l2.c - l1.c*l2.b)/det;
    ld y = (l1.c*l2.a - l1.a*l2.c)/det;
    return {pt(x, y)};
}

vp intersecSeg(line l1, line l2){ // intersec of two line seg 
    vp ans = intersecLine(l1, l2);
    if(ans.empty() || !l1.insideSeg(ans[0]) || !l2.insideSeg(ans[0]))
        return {};
    return ans;
}

ld dSeg(pt p, pt a, pt b){ // distance - pt to line seg
    if(((p-a)*(b-a)) < EPS) return norm(p-a);
    if(((p-b)*(a-b)) < EPS) return norm(p-b);
    return abs((p-a)^(b-a))/norm(b-a);
}

ld dLine(pt p, line l){ // pt - line
    return abs(l.eval(p))/sqrt(l.a*l.a + l.b*l.b);
}

bool paraline(line r, line s) { // se r e s sao paralelas
    return paral(r.p1 - r.p2, s.p1 - s.p2);
}

line perpendicular(line l, pt p){ // passes through p
    return line(l.b, -l.a, -l.b*p.x + l.a*p.y);
}

line bisector(line l){ // bisctor of a line segment
    pt mid = pt((l.p1.x + l.p2.x)/2, (l.p1.y + l.p2.y)/2);
    return perpendicular(l, mid);
}



//\ POLIGONO /\\

ld area(vp &p){ // polygon area (pts sorted)
    ld ret = 0;
    for(int i=2; i<(int)p.size(); i++){
        ret += (p[i]-p[0])^(p[i-1]-p[0]);
    }
    return abs(ret/2);
}

int isInside(vector<pt>& v, pt p) { // O(n) - pt inside polygon
    int qt = 0; // 0 outside /  1 inside / 2 border
    for (int i = 0; i < (int)v.size(); i++) {
        if (p == v[i]) return 2;
        int j = (i+1)%v.size();
        if (eq(p.y, v[i].y) && eq(p.y, v[j].y)) {
            if ((v[i]-p)*(v[j]-p) < EPS) return 2;
            continue;
        }
        bool baixo = v[i].y+EPS < p.y;
        if (baixo == (v[j].y+EPS < p.y)) continue;
        auto t = (p-v[i])^(v[j]-v[i]);
        if (eq(t, 0)) return 2;
        if (baixo == (t > EPS)) qt += baixo ? 1 : -1;
    }
    return qt != 0;
}

bool isIntersec(vector<pt> v1, vector<pt> v2) { // 2 polygons intersec- O(n*m)
    int n = v1.size(), m = v2.size();
    for (int i = 0; i < n; i++) if (isInside(v2, v1[i])) return 1;
    for (int i = 0; i < n; i++) if (isInside(v1, v2[i])) return 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        if (intersecSeg(line(v1[i], v1[(i+1)%n]), line(v2[j], v2[(j+1)%m])).size() != 0) return 1;
    return 0;
}

// ld distPol(vector<pt> v1, vector<pt> v2) { // distancia de poligonos
//     if (isIntersec(v1, v2)) return 0;

//     ld ret = DINF;
//     for (int i = 0; i < v1.size(); i++){
//         for (int j = 0; j < v2.size(); j++){
//             ret = min(ret, dSeg(line(v1[i], v1[(i + 1) % v1.size()]),
//                     line(v2[j], v2[(j + 1) % v2.size()])));
//         }
//     }
//     return ret;
// }

//\ Circle /\\


struct circle{
    pt c; T r;
    circle() : c(0, 0), r(0){}
    circle(const pt o) : c(o), r(0){}
    circle(const pt a, const pt b){
        c = (a+b)/2;
        r = norm(a-c);
    }
    bool inside(const pt &a) const{
        return norm(a - c) <= r;
    }
    pair<pt, pt> getTangent(pt p) {
        ld d1 = norm(p-c), theta = asin(r/d1);
        pt p1 = rotccw(c-p,-theta);
        pt p2 = rotccw(c-p,theta);
        p1 = p1*(sqrt(d1*d1-r*r)/d1)+p;
        p2 = p2*(sqrt(d1*d1-r*r)/d1)+p;
        return {p1,p2};
    }
};



circle incircle( pt p1, pt p2, pt p3 ){
    ld m1=norm(p2-p3);
    ld m2=norm(p1-p3);
    ld m3=norm(p1-p2);
    pt c = (p1*m1+p2*m2+p3*m3)*(1/(m1+m2+m3));
    ld s = 0.5*(m1+m2+m3);
    ld r = sqrt(s*(s-m1)*(s-m2)*(s-m3))/s;
    return circle(c, r);
}

circle circumCircle(pt a, pt b, pt c) {
    circle ans;
    pt u = pt((b-a).y, -(b-a).x);
    pt v = pt((c-a).y, -(c-a).x);
    pt n = (c-b)*0.5;
    ld t = (u^n)/(v^u);
    ans.c = ((a+c)*0.5) + (v*t);
    ans.r = norm(ans.c-a);
    return ans;
}

vp intersecCircleLine(circle C, line L){
    pt ab = L.p2 - L.p1, p = L.p1 + ab * ((C.c-L.p1)*(ab) / (ab*ab));
    ld s = (L.p2-L.p1)^(C.c-L.p1), h2 = C.r*C.r - s*s / (ab*ab);
    if (h2 < 0) return {};
    if (h2 == 0) return {p};
    pt h = (ab/norm(ab)) * sqrt(h2);
    return {p - h, p + h};
}

vp intersecCircles(circle C1, circle C2){
    if(C1.c == C2.c) { assert(C1.r != C2.r); return {}; }
    pt vec = C2.c - C1.c;
    ld d2 = vec*vec, sum = C1.r+C2.r, dif = C1.r-C2.r;
    ld p = (d2 + C1.r*C1.r - C2.r*C2.r)/(d2*2), h2 = C1.r*C1.r - p*p*d2;
    if (sum*sum < d2 or dif*dif > d2) return {};
    pt mid = C1.c + vec*p, per = pt(-vec.y, vec.x) * sqrt(max((ld)0, h2) / d2);
    if(eq(per.x, 0) and eq(per.y, 0)) return {mid};
    return {mid + per, mid - per};
}

// circle minCircleCover(vector<pt> v){ // O(n) min circle that cover all pts 
//     // random_shuffle(v.begin(), v.end());
//     circle ans;
//     int n = v.size();
//     for(int i=0;i<n;i++) if(!ans.inside(v[i])){
//         ans = circle(v[i]);
//         for(int j=0;j<i;j++) if(!ans.inside(v[j])){
//             ans = circle(v[i], v[j]);
//             for(int k=0;k<j;k++) if(!ans.inside(v[k])){
//                 ans = circle(v[i], v[j], v[k]);
//             }
//         }
//     }
//     return ans;
// }

//\ EXTRA C++ complex library /\\

typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()

pt p{3,-4};
cout << p.x << " " << p.y << "\n"; // 3 -4
cout << p << "\n"; // (3,-4)

pt p{-3,2};
p.x = 1; // doesn’t compile
p = {1,2}; // correct

pt a{3,1}, b{1,-2};
a += 2.0*b; // a = (5,-3)
cout << a*b << " " << a/-b << "\n"; // (-1,-13) (-2.2,-1.4)// typedef int T;
// bool eq(T a, T b){ return (a==b); }
typedef ld T; // or int
bool eq(T a, T b){ return abs(a - b) <= EPS; }
