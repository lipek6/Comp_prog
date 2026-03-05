#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<bool> nums_dfs;

void dfs (int u)
{
    nums_dfs[u] = true;

    for(int i = 0; i < AL[u].size(); i++)
    {
        if(nums_dfs[AL[u][i]] == false)
            dfs(AL[u][i]);
    }
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    int a, b;

    // Ignoring zero index
    AL.resize(n + 1);
    nums_dfs.resize(n + 1);
    fill(nums_dfs.begin(), nums_dfs.end(), 0);


    // He will give me a adjacency list (at least I can treat it like that)
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    dfs(1);     // The amount of required road is the amount of CCs - 1, so we can run a dfs before looping to avoid counting a extra road
    int k = 0;
    vector<pair<int, int>> to_connect;
    for(int i = 1; i < n + 1; i++)
    {
        if(nums_dfs[i] == false) //UNVISITED
        {
            dfs(i);
            k++;
            to_connect.push_back({i - 1, i});
        }
    }
    cout << k << "\n";
    for(int i = 0; i < k; i++) 
    {
        cout << to_connect[i].first << " " << to_connect[i].second << "\n";
    }
}