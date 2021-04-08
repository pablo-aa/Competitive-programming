// LCS  maior subs comum
// a,b = indice maximo do vetor
// s1={1,2,3}  a = 2
#define MAXN 1010

int s1[MAXN], s2[MAXN], tab[MAXN][MAXN];

int lcs(int a, int b){
    
    if(a == 0 || b == 0) return tab[a][b] = 0;

    if(tab[a][b] != -1) return tab[a][b];

    if(s1[a] == s2[b]) return lcs(a-1,b-1)+1;

    return tab[a][b] = max(lcs(a-1, b), lcs(a, b-1));
}