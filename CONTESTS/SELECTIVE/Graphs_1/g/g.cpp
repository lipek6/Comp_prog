#include<bits/stdc++.h>
using namespace std;

// Argumento da troca
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    
    while(tc--)
    {
        int n, d; cin >> n >> d;
        vector<vector<pair<int,int>>> AL;
        vector<int> p(n+1);
        vector<int> t(n+1);

        for(int i = 1; i <= n; i++) cin >> p[i];
        for(int i = 1; i <= n; i++) cin >> t[i];
        
        for(int i = 1; i <= n; i++)
        {
            AL.push_back({p[i], t[i] + p[i-1]})
        }
    }
}