/**
 * BIBLIOTECA DE STRINGS
 * * Conteúdo:
 * 1. KMP (Knuth-Morris-Pratt) - Busca exata rápida O(N+M).
 * 2. Z-Function - Array de prefixos comuns.
 * 3. Hashing Polinomial - Comparação O(1) após pré-processamento.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==================================================================================
// 1. KMP (Knuth-Morris-Pratt)
// O coração do KMP é a função PI (prefix function).
// pi[i] = comprimento do maior prefixo próprio da substring s[0...i] 
//         que também é sufixo dessa substring.
// Ideal para: CSES "String Matching", encontrar padrão em texto.
// ==================================================================================
vector<int> compute_pi(const string& P) {
    int m = P.size();
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) {
        // Se letras não batem, voltamos 'j' para o melhor prefixo anterior conhecido
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        
        if (P[i] == P[j])
            j++;
        
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp_search(const string& T, const string& P) {
    vector<int> matches;
    vector<int> pi = compute_pi(P);
    int n = T.size();
    int m = P.size();

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j])
            j = pi[j - 1]; // Fallback inteligente
        
        if (T[i] == P[j])
            j++;

        if (j == m) {
            // Encontrou ocorrência terminando em i
            matches.push_back(i - m + 1);
            j = pi[j - 1]; // Prepara para próxima busca
        }
    }
    return matches;
}

// ==================================================================================
// 2. Z-FUNCTION
// z[i] é o comprimento do maior prefixo comum entre s e o sufixo de s começando em i.
// Útil para pattern matching concatenando P + "$" + T.
// Ideal para: CSES "Finding Borders".
// ==================================================================================
vector<int> z_function(const string& s) {
    int n = s.length();
    vector<int> z(n);
    // [l, r] é o intervalo do "Z-box" (segmento que dá match com prefixo)
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// ==================================================================================
// 3. STRING HASHING (Rolling Hash)
// Permite comparar substrings em O(1).
// Hash(s) = (s[0]*B^n-1 + s[1]*B^n-2 + ... + s[n-1]*B^0) % M
// Ideal para: CSES "Palindrome Queries", Gym "Secret Words".
// ==================================================================================
struct StringHash {
    vector<long long> h, p;
    long long MOD = 1e9 + 9; // Primo grande
    long long BASE = 31;     // Base maior que nro de caracteres (26 minúsculas)

    StringHash(const string& s) {
        int n = s.size();
        h.resize(n + 1, 0);
        p.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h[i+1] = (h[i] * BASE + (s[i] - 'a' + 1)) % MOD;
            p[i+1] = (p[i] * BASE) % MOD;
        }
    }

    // Retorna hash da substring [l, r] (0-based inclusive)
    long long get_hash(int l, int r) {
        // Fórmula: H[r+1] - H[l] * B^(len)
        long long res = (h[r+1] - h[l] * p[r - l + 1]) % MOD;
        if (res < 0) res += MOD;
        return res;
    }
};