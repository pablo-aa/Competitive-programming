// Function to find all Sub palindromes
// O(n*n)

string s; // n = s.size();
vector<vector<bool> > is_pal(n, vector<bool>(n, true)); 

// formando todos os subpalindromos
forne(k, 1, n-1)
	forne(i, 0, n-k-1)
		is_pal[i][i+k] = (s[i]==s[i+k] && is_pal[i+1][i+k-1]);