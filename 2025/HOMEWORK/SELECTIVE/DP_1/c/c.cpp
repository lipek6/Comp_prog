#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t; cin >> s >> t; if(t.size() > s.size()) swap(s, t);
    string w;

    if(s == t)
    {
        cout << s << "\n";
        return 0;
    }
    if(s.empty() || t.empty())
    {
        cout << w << "\n";
        return 0;
    }
    
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));


    // Computing
    for(int i = 0; i <= s.size(); i++)
    {
        for(int j = 0; j <= t.size(); j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Reconstructing the answer
    int i = s.size();
    int j = t.size();
    while(true)
    {
        if(i <= 0 || j <= 0) break;

        if(s[i-1] == t[j-1])
        {
            w += s[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(w.begin(), w.end());
    cout << w << "\n";
}