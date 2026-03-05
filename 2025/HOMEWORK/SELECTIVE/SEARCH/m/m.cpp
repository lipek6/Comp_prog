#include<bits/stdc++.h>
using namespace std;

bool TryDistance(long long m, vector<int>& x, int& n, int& c)
{
    int cown_count = 0;
    int i = 0;
    while(i < n)
    {
        int j = 0;
        while(x[i + j] - x[i] < m && i + j < n)
        {
            j++;
        }
        i += j;
        cown_count++;
    }

    if(cown_count < c)
        return false;
    else
        return true;
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    
    while(t--)
    {
        int n, c; cin >> n >> c;

        vector<int> x(n);
        for(int i = 0; i < n; i++) cin >> x[i];
        sort(x.begin(), x.end());
        
        
        long long m;
        long long l = 0LL;
        long long r = x[n-1] - x[0]; // Max distance between two stalls
        long long min_dist = r;

        while(l <= r)
        {
            m = l + (r - l) / 2;
            
            if(TryDistance(m, x, n, c))
            {
                min_dist = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        
        }
        cout << min_dist << "\n";
    }
}