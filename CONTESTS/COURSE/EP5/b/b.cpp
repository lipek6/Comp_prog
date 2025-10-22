#include<bits/stdc++.h>
using namespace std;

// It was dp and I though it was greedy :(
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;           // Number of rocks and maximum jump distance
    cin >> n >> k;
    
    // Height vector with index correction
    vector<int> h(n + 1);
    for(int i = 1; i < n + 1; i++) cin >> h[i];

    vector<long long> dp(n + 1, LLONG_MAX);     // total optimal costs at each rock
    dp[1] = 0;                                  // Base case, from rock 1 to rock 1 the cost is h1 - h1 = 0

    for (int i = 2; i < n + 1; i++)            
    {
        for (int j = i - 1; j >= 1 && j >= i - k; j--)      // Check where we can go from j to i (backwards), considering the k constraint and the bottom of the vector
        {
            long long cost = dp[j] + abs(h[i] - h[j]);      // Total cost considering the current path, it's the cost + the old costs
            dp[i] = min(dp[i], cost);                       // Select the best option to put into the dp
        }

    }
    cout << dp[n] << endl;                                  // dp[n] contains the optimal minimal cost to get from 1 to n
}