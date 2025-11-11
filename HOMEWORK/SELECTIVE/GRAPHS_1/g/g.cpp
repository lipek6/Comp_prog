#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    
    AL.assign(n+1);
    for(int i = 0; i < m; i++)
    {
        int guy1, guy2;
        cin >> guy1 >> guy2;
        
        AL[guy1].push_back(guy2);
        AL[guy2].push_back(guy1);
    }

    int minimum_bonds = m;
    
    for(int i = 1; i <= n; i++)
    {
        if(dfs_states[i] == UNVISITED)
        {
            dfs(i);

        }
    }






}