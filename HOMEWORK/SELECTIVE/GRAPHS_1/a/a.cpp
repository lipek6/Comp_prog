#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc; cin >> tc;
    
    while(tc--)
    {
        int n; cin >> n;
        
        vector<pair<int,int>> degrees(n+1);
        vector<vector<int>> AL(n+1);

        for(int i = 0; i < (n - 1); i++)
        {
            int u, v; cin >> u >> v;
    
            AL[u].push_back(v);
            AL[v].push_back(u);
        }
    
        for(int i = 1; i <= n; i++) degrees[i] = {AL[i].size(), i};

        sort(degrees.begin(), degrees.end(), greater<pair<int,int>>());
        

        vector<bool> neighboors0(n+1, false);
        vector<bool> neighboors1(n+1, false);

        int max_components = degrees[0].first + degrees[1].first - 1;
    
        for(int adj : AL[degrees[0].second]) neighboors0[adj] = true;
        for(int adj : AL[degrees[1].second]) neighboors1[adj] = true;
        if(neighboors0[degrees[1].second]) max_components--;

        
        for(int i = 2; i < n; i++)
        {
            
            int choose0 = degrees[0].first + degrees[i].first - 1;
            int choose1 = degrees[1].first + degrees[i].first - 1;
            if (choose0 <= max_components) break;

            if(neighboors0[degrees[i].second]) choose0--; 

            max_components = max(max_components, choose0);

            if(choose1 > max_components)
            {
                if(neighboors1[degrees[i].second]) choose1--; 

                max_components = max(max_components, choose1);
            }
        }
        cout << max_components << "\n";
    }
}