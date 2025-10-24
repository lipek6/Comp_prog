#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main (void)
{
    // The (fucking) idea here is to make dp hold the optimal cost to get to the total capacity of passangers:
    // So: dp[0] = 0; 
    //     dp[1] = best price to alocate 1 guy  at the cars;
    //     dp[2] = best price to alocate 2 guys at the cars;
    //     dp[3] = best price to alocate 3 guys at the cars;
    //     dp[4] = best price to alocate 4 guys at the cars...


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x, n; cin >> x >> n;           // Number of marathonists and available ride options

    vector<ll> p(n);       // Passengers
    vector<ll> v(n);       // Values
    
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
    
    vector<ll> dp(total_capacity + 1, LLONG_MAX);    // Minimal cost to get to a total capacity of idx
    dp[0] = 0;

    for(int i = 0; i < n; i++)
    {
        int capacity = p[i];
        int cost     = v[i];
        for(int k = total_capacity; k >= capacity; k--)
        {
            if (dp[k - capacity] != LLONG_MAX)
            {
                dp[k] = min(dp[k], dp[k - capacity] + cost);
            }
        }
    }

    // cout << dp[x] << "\n"; We cannot simply print the cost to transport x guys
    // There is the chance that trasporting more than x guys is cheaper

    ll min_cost = LLONG_MAX;
    for (int k = x; k <= total_capacity; k++)
    {
        min_cost = min(min_cost, dp[k]);
    }
    cout << min_cost << "\n";
}