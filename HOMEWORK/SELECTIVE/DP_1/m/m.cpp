#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b, c; cin >> n >> m >> a >> b >> c;
    string s, t; cin >> s >> t;

    vector<vector<int>> dp(n+1, vector<int>(m+1));
    dp[0][0] = 0;
    for(int i  = 1; i < n+1; i++)
        dp[i][0] = dp[i-1][0] + b;
    for(int j = 1; j < m+1; j++)
        dp[0][j] = dp[0][j-1];

    for(int i  = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++)
        {
            if(s[i-1] == t[j-1])
                cost = dp[i-1][j-1];
            else
                cost = dp[i-1][j-1] + c;
        }
    }

}