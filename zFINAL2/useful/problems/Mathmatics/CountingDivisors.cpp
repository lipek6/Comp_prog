#include<bits/stdc++.h>
using namespace std;

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




int numDiv(long long N)
{
    int divisors = 1;
    
    for(int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i)    
    {
        int power = 0;
        while (N%p[i] == 0)
        { 
            N /= p[i]; 
            ++power;
        }
        divisors *= power + 1;
    }

    return (N != 1) ? 2 * divisors : divisors;
}




int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    long long num;
    sieve(1e6);

    long long MAX = 1e6;
    while(n--)
    {
        cin >> num;
        cout << numDiv(num) << "\n";
    }
}