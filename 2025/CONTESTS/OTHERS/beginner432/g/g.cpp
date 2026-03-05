#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n);
    vector<unsigned long long int> fact(n*m); fact[0] = 0; fact[1] = 1; fact[2] = 2; fact[3] = 6;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < m; i++)cin >> b[i];

    for(int i = 4; i < n*m; i++)
    {  
        fact[i] = fact[i-1] * i;
    }

    unsigned long long int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i] < b[j]) continue;

            unsigned long long int denominator = fact[b[j]] * (fact[a[i] - b[j]]);
            unsigned long long int numerator   = fact[a[i]];
            sum += (numerator / denominator);
        }
    }
    cout << sum % 998244353 << "\n"; 
}