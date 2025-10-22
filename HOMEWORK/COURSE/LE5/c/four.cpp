#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x, n; cin >> x >> n;           // Number of marathonists and available ride options

    vector<ll> p(n);       // Passengers
    vector<ll>  v(n);       // Values
    
    ll total_capacity = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> p[i] >> v[i];        // Number of passengers and the charge for the trip
        total_capacity += p[i];
    }

    if (x > total_capacity)
    {
        cout << "-1" << "\n";
        return 0;        
    }
    
    vector<pair<ll, ll>> dp(n);    // Remaining people and total value dp
    dp[0].first  = x - p[0];
    dp[0].second = 0 + v[0];

    for(int i = 1; i < n; i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            ll ratio  = dp[j].second / dp[j].first;
            ll remain = x - dp[j].first;
            ll value  = dp[j] + dp[i];

            if(ratio < dp[i] / )
            // ith and jth needs to go to zero
        }
    }
    
    cout << dp[n-1].second << endl;
}