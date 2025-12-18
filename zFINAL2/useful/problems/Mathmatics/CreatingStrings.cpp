#include<bits/stdc++.h>
using namespace std;
const long long m = 1e9 + 7;

vector<long long> factorials(1e7);

int extEuclid(int a, int b, int &x, int &y)
{
    int xx = y = 0;
    int yy = x = 1;

    while (b)
    {
        int q = a/b;
        int t = b; b = a%b;  a = t;
        t = xx; xx = x-q*xx; x = t;
        t = yy; yy = y-q*yy; y = t; 
    }
    return a;
}

int mod(int a, int m)
{ 
    return ((a%m) + m) % m;
}

int modInverse(int b, int m)
{
    int x, y;

    int d = extEuclid(b, m, x, y); 
    
    if (d != 1) return -1; 

    return mod(x, m);
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    factorials[0] = 1;

    string str; cin >> str;

    long long fact_n = 1;
    for(int i = 1; i < 2 * 1e6; i++)
    {
        fact_n = ((fact_n % m) * (i % m)) % m;
        factorials[i] = fact_n;
    }

    vector<int> letter_counter(26);
    for(int i = 0; i < str.size(); i++) letter_counter[(str[i] - 'a')]++;
    
    long long result = factorials[str.size()];

    for(long long reps : letter_counter)
    {
        result = ((result % m) * modInverse(factorials[reps], m)) % m;
    }

    cout << result << "\n";
}