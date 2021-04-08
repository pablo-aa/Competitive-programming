// Maximum possible sum in Array
// O(n)
int array[MAXN];

int kadane(){
    int sum = 0, best = 0;
    for(int i = 0; i < n; i++){
        sum = max(array[i], sum+array[i]);
        best = max(sum, best);
    }

    return best;
}