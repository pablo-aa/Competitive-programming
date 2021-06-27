// Matrix Exponentiation
// O(log n)
#define ll long long int
#define vl vector<ll>
struct Matrix {
    vector<vl> m;
    int r, c;

    Matrix(vector<vl> mat) {
        m = mat;
        r = mat.size();
        c = mat[0].size();
    }

    Matrix(int row, int col, bool ident=false) {
        r = row; c = col;
        m = vector<vl>(r, vl(c, 0));
        if(ident) 
            for(int i = 0; i < min(r, c); i++) 
                m[i][i] = 1;
    }

    Matrix operator*(const Matrix &o) const {
        assert(c == o.r); // garantir que da pra multiplicar
        vector<vl> res(r, vl(o.c, 0));

        for(int i = 0; i < r; i++) 
            for(int j = 0; j < o.c; j++) 
                for(int k = 0; k < c; k++) 
                    res[i][j] = (res[i][j] + m[i][k]*o.m[k][j]) % 1000000007;

        return Matrix(res);
    }

    void printMatrix(){
    	for(int i = 0; i < r; i++)
    		for(int j = 0; j < c; j++)
    			cout << m[i][j] << " \n"[j == (c-1)];
    }
};

Matrix fexp(Matrix b, ll e, int n) {
    if(e == 0) return Matrix(n, n, true); // identidade
    Matrix res = fexp(b, e/2LL, n);
    res = (res * res);
    if(e%2) res = (res * b);

    return res;
}

// Fibonacci Example O (log n)
/*  Fibonacci
    |1 1|*|Fn  | = |Fn+1|
    |1 0| |Fn-1|   |Fn  |

    Generic
    |a1 a2 ... an| ** K *  |Fn-1| = |Fk+n-1|
    |1 0   ...  0|         |Fn-2|   |Fk+n-2|
    |0 1 0 ...  0|         |Fn-3|   |Fk+n-3|
           ...              ...      ...
    |0 0 0 ...1 0|         |F0  |   |Fk    |
*/

int main() {
    ll n;
    cin >> n; // Fibonacci(n)
 
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vl> m = {{1LL, 1LL}, {1LL, 0LL}};
    vector<vl> b = {{1LL}, {0LL}};
 
    Matrix mat = Matrix(m);
    Matrix base = Matrix(b);
 
    mat = fexp(mat, n-1, 2);
    mat = mat*base;
 
    cout << mat.m[0][0] << endl;
 
 
    return 0;
}