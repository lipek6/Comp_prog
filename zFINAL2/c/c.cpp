#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1000005;
int spf[MAX_N];

void sieve()
{
    for (int i = 1; i < MAX_N; i++) spf[i] = i;
    
    for (int i = 2; i * i < MAX_N; i++)
    {
        if (spf[i] == i)
        { // i is prime
            for (int j = i * i; j < MAX_N; j += i)
            {
                if (spf[j] == j) spf[j] = i; // Marca o menor primo que divide j
            }
        }
    }
}

map<int, int> get_prime_factorization(int n)
{
    map<int, int> factors;
    while(n > 1)
    {
        factors[spf[n]]++;
        n /= spf[n];
    }
    return factors;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve();
    int n, q; cin >> q;
    
    while(q--)
    {
        cin >> n;
        if(spf[n] != 2)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}