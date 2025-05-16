// KMP (Knuth-Morris-Pratt)
// O(n + m)

// Computa a função de borda (prefixo-sufixo) para o padrão
// e realiza busca de padrão em texto em tempo linear

// Retorna todas as posições onde o padrao ocorre no texto

vector<ll> compute_prefix(const string &pattern) {
    ll m = pattern.size();
    vector<ll> border(m, 0);
    
    for (ll i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = border[j-1];
            
        if (pattern[i] == pattern[j])
            j++;
            
        border[i] = j;
    }
    
    return border;
}

vector<ll> kmp(const string &text, const string &pattern) {
    vector<ll> positions;
    ll n = text.size();
    ll m = pattern.size();
    
    if (m == 0 || m > n) return positions;
    
    vector<ll> border = compute_prefix(pattern);
    
    for (ll i = 0, j = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = border[j-1];
            
        if (text[i] == pattern[j])
            j++;
            
        if (j == m) {
            positions.push_back(i - m + 1); // Posição onde o padrão começa
            j = border[j-1];
        }
    }
    
    return positions;
}

// Usa KMP para verificar se um padrão é substring do texto
bool is_substring(const string &text, const string &pattern) {
    return !kmp(text, pattern).empty();
} 