// Thanks, my beloved lib
#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t; cin >> s >> t;


    if(s.empty())
        {cout << t.size() << "\n"; return 0;}
    else if(t.empty())
        {cout << t.size() << "\n"; return 0;}

    int slen = s.length();
    int tlen = t.length();

    vector<vector<int>> dp(slen + 1, vector<int>(tlen + 1));
    int temp = 0;

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
                    temp = dp[i-1][j];
                else
                    temp = dp[i][j-1];

                if(dp[i-1][j-1] < temp)
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 1 + temp;
            }
        }
    }
    cout << dp[slen][tlen] << "\n";
}