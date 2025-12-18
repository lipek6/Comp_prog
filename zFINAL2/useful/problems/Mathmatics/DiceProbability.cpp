#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b; cin >> n >> a >> b;

    // Matrix of the probabilities to do a DP, aaaaa, I need a vacation, I am completely tired of having to do one hundred things at the same day
    // This cadeira is cool, but how the fuck am I expected to read this chapter??? more then 50 pages about a huge amount of topics to read in a week?
    // Mate, I am almost not studying for normal cadeiras because I need to focus on those things and on the selective.
    vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1, 0.0));
    double result = 0.0;

    dp[0][0] = 1.0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 6 * i; j++)
        {
            for(int face = 1; face <= 6; face++)
            {
                if(j - face >= 0) dp[i][j] += dp[i-1][j - face];
            }
            dp[i][j] = dp[i][j] / 6.0;
        }
    }
    
    for(int i = a; i <= b; i++)
    {
        if(i <= 6 * n) result += dp[n][i];
    }

    cout << fixed << setprecision(6) << result << "\n";

}