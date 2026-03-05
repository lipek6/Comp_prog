#include<bits/stdc++.h>
using namespace std;

const long long m = 1e9 + 7;

long long _sieve_size;
bitset<10000010> bs; 
vector<long long> p;

void sieve(long long upperbound)
{
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(long long i = 2; i < _sieve_size; ++i) 
    {
        if(bs[i])
        {
            for (long long j = i*i; j < _sieve_size; j += i) bs[j] = 0;
            p.push_back(i);
        }
    }
}

int sumDiv(long long N)
{
    long long divs_sum = 1;
    
    for(int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i)    
    {
        long long multiplier = p[i];
        long long total = 1;
        while (N%p[i] == 0)
        { 
            N /= p[i]; 
            total += multiplier;
            multiplier *= p[i];
        }
        divs_sum *= total;
    }

    return (N != 1) ? divs_sum * (N+1) : divs_sum;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve(1e7);

    long long n; cin >> n;
    long long result = 0;

    for(int i = 1; i <= n; i++)
    {
        result += i;
    }
    
    cout << sumDiv(result) - n << "\n";
}