#include<bits/stdc++.h>
using namespace std;

// at least 2
// each pair of indices i and j the greatest common divisor (GCD) of aiai​ and ajaj​ is equal to 11

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> presum;
    vector<int> primes;
    bitset<(long long)1e7> composed;
    
    for(int i = 2; i < 1e7; i++)
    {
        if(!composed[i])
        {
            primes.push_back(i);
            if(primes.size() >= 1e6) break;
        }

        for(long long j = (long long)i * i; j < 1e7; j += i) composed[j] = 1;
    }

    presum.push_back(0);
    long long sum = 0;
    for(int prime : primes)
    {
        sum += prime;
        presum.push_back(sum);
    }

    int tc; cin >> tc;
    while(tc--)
    {
        int n; cin >> n;

        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end(), greater());

        int maximal = 0;
        long long curr_sum = 0;

        for(int i = 0; i < n; i++)
        {
            curr_sum += a[i];
            if(curr_sum >= presum[i + 1])
                maximal = i + 1;
            else
                break;
        }

        cout << n - maximal << "\n";
    }






}