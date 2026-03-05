#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;

    int slen = s.size();
    int tlen = t.size();
    
    vector<vector<int>> dp(slen + 1, vector<int>(tlen + 1));
    int holder = 0;

    for(int i = 0; i <= slen; i++)
    {
        for(int j = 0; j <= tlen; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
            {
                if(dp[i-1][j] < dp[i][j-1])
                    holder = dp[i-1][j];
                else
                    holder = dp[i][j-1];

                if(dp[i-1][j-1] < holder)
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 1 + holder;
            }
        }
    }
    cout << dp[slen][tlen] << "\n";
}