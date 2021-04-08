// Segtree MAX
// O(log n) operations

// DESCRIPTION:
// sti: id do nodo que estamos na segment tree
// stl: limite inferior do intervalo que aquele nodo representa(inclusivo)
// str: limite superior do intervalo que aquele nodo representa(inclusivo)
// l : limite inferior do intervalo que queremos fazer a consulta
// r : limite superior do intervalo que queremos fazer a consulta
// i : indice do vetor que queremos atualizar
// amm: novo valor daquele indice no vetor

class SegTree{
    vector<int> st;
    vector<int> lazy;
    vector<bool> has;
    int size;

    int el_neutro = -(1e9 + 7);

    int f(int a, int b){
        return max(a,b);
    }

    void propagate(int sti, int stl, int str){
        if(has[sti]){
            st[sti] = lazy[sti]*(str-stl+1);
            if(stl!=str){
                lazy[sti*2+1] = lazy[sti];
                lazy[sti*2+2] = lazy[sti];

                has[sti*2+1] = true;
                has[sti*2+2] = true;
            }
            has[sti] = false;
        }
    }

    int query(int sti, int stl, int str, int l, int r){
        if(str < l || stl > r) return el_neutro;

        if(stl >= l && str <= r)
            return st[sti];

        // intervalo parcialmente incluido em l-r
        int mid = (stl+str)/2;

        return f(query(2*sti+1, stl, mid, l, r), query(2*sti+2, mid+1, str, l, r));
    }

    void update(int sti, int stl, int str, int i, int amm){
        if(stl == i && str == i){
            st[sti] += amm;
            return;
        }

        if(stl > i || str < i) return;

        int mid = (stl+str)/2;

        // Processo de atualizacao dos nos filhos
        update(sti*2+1, stl, mid, i, amm);
        update(sti*2+2, mid+1, str, i, amm);

        st[sti] = f(st[sti*2+1], st[sti*2+2]);
    }

    void update_range(int sti, int stl, int str, int l, int r, int amm){
        if(stl >= l && str <= r){
            lazy[sti] = amm;
            has[sti] = true;
            propagate(sti, stl, str);
            return;
        }

        if(stl > r || str < l) return;

        int mid = (stl+str)/2;
        update_range(sti*2+1, stl, mid, l, r, amm);
        update_range(sti*2+2, mid+1, str, l, r, amm);

        st[sti] = f(st[sti*2+1],st[sti*2+2]);
    }

    public:
        SegTree(int n): st(4*n, 0){size=n;}
        int query(int l, int r){return query(0,0,size-1,l,r);}
        void update(int i, int amm){update(0,0,size-1,i,amm);}
        void update_range(int l, int r, int amm){update_range(0,0,size-1,l,r,amm);}
};

// In main()

SegTree st(v.size());

for(int i = 0; i < n; i++){
    st.update(i, v[i]);
}


