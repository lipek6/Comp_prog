#include<bits/stdc++.h>
#define INF 1e18
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k; cin >> n >> k;

    vector<long long> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    vector<long long> dp(n, INF);
    dp[0] = 0;                                                   // No cost from the origin to the origin

    for(int i = 0; i < n; i++)                                   // For all the stones
    {
        for(int j = 1; j <= k; j++)                              // Check the stones on reach
        {
            if(i+j >= n) break;

            long long jump_cost = abs(h[i] - h[i+j]);                    // Cost to get to the stone without considering accumulated cost

            dp[i+j] = min(dp[i] + jump_cost, dp[i+j]);           // Save the best cost on the array
        }
    }
    cout << dp[n-1] << "\n";
}