/**
 * BIBLIOTECA DE TEORIA DOS NÚMEROS
 * * Conteúdo:
 * 1. Crivo de Eratóstenes (SPF) - Fatoração rápida.
 * 2. Exponenciação Modular - Calcular (a^b) % m em O(log b).
 * 3. Inverso Modular & Combinatória (nCr) - Para calcular combinações grandes % P.
 * 4. GCD e LCM.
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// ==================================================================================
// 1. CRIVO E FATORAÇÃO
// Pré-calcula o Smallest Prime Factor (SPF) para cada número até MAX_N.
// Permite fatorar qualquer número N <= MAX_N em O(log N).
// Ideal para: CSES "Counting Divisors", "Prime Factors".
// ==================================================================================
const int MAX_N = 1000005;
int spf[MAX_N];

void sieve() {
    for (int i = 1; i < MAX_N; i++) spf[i] = i;
    
    for (int i = 2; i * i < MAX_N; i++) {
        if (spf[i] == i) { // i é primo
            for (int j = i * i; j < MAX_N; j += i) {
                if (spf[j] == j) spf[j] = i; // Marca o menor primo que divide j
            }
        }
    }
}

map<int, int> get_prime_factorization(int n) {
    map<int, int> factors;
    while (n > 1) {
        factors[spf[n]]++;
        n /= spf[n];
    }
    return factors;
}

// ==================================================================================
// 2. EXPONENCIAÇÃO MODULAR
// Calcula (base^exp) % mod eficientemente usando exponenciação binária.
// Se exp for par: x^n = (x^2)^(n/2)
// Se exp for ímpar: x^n = x * x^(n-1)
// Ideal para: "Modular Arithmetic", Criptografia RSA simples.
// ==================================================================================
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// ==================================================================================
// 3. INVERSO MODULAR & COMBINATÓRIA (nCr)
// Para calcular nCr % P (onde P é primo), precisamos dividir por (r! * (n-r)!).
// Em modular, dividir por X é multiplicar pelo inverso modular de X.
// Pelo Pequeno Teorema de Fermat, inv(a) = a^(P-2) % P.
// Ideal para: "Binomial Theorem".
// ==================================================================================
const long long MOD = 1e9 + 7;
const int MAX_FAT = 200005;
long long fact[MAX_FAT], invFact[MAX_FAT];

// Inverso modular usando Fermat (funciona se MOD for primo)
long long modInverse(long long n) {
    return power(n, MOD - 2, MOD);
}

void precompute_factorials() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX_FAT; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

// ==================================================================================
// 4. GCD e LCM
// GCD: Algoritmo de Euclides. __gcd(a, b) do C++ já faz isso, mas é bom saber.
// LCM: (a * b) / GCD(a, b). Cuidado com overflow em a*b!
// Ideal para: "Array and GCD".
// ==================================================================================
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (a / gcd(a, b)) * b; // Divide antes para evitar overflow
}