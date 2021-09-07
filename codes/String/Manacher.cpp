// Manacher Algorithm
// O(n)

// Find all sub palindromes in a string
// d1 = Odd palin, d2 = Even palin

vector<int> manacher(string &s, vector<int> &d1, vector<int> &d2) {
    int n = s.size();
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while(0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if(i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while(0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if(i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }

    // special vector to construct query by interval
    vector<int> res(2*n-1);
    for (int i = 0; i < n; i++) res[2*i] = 2*d1[i]-1;
    for (int i = 0; i < n-1; i++) res[2*i+1] = 2*d2[i+1];
    return res;

}

struct palindrome {
    vector<int> res;

    palindrome(const& s): res(manacher(s)){}

    // Query if [i..j] is palindrome
    bool is_palindrome(int i, int j){
        return res[i+j] >= j-i+1;
    }
}