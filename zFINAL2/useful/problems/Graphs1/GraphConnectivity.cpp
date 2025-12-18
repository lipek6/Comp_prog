#include<bits/stdc++.h>
using namespace std;

// Creating an adjacency list
vector<vector<int>> AL;

// Creating a DFS
vector<bool> dfs_num;
void dfs(int u)
{
    dfs_num[u] = true;
    for(int v = 0; v < AL[u].size(); v++)
    {
        if(dfs_num[AL[u][v]] == false)
            dfs(AL[u][v]);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    int num_nodes;

    int t; cin >> t;
    cin.ignore();
    cin.ignore();
    while(t--)
    {
        getline(cin, str);

        num_nodes = str[0] - 'A' + 1;
        dfs_num.assign(num_nodes, 0);
        AL.assign(num_nodes, vector<int>());

        while(getline(cin, str) && !str.empty())
        {
            AL[str[0] - 'A'].push_back(str[1] - 'A');
            AL[str[1] - 'A'].push_back(str[0] - 'A');
        }

        int count = 0;
        for(int u = 0; u < num_nodes; u++)
        {
            if(dfs_num[u] == false)
            {
                dfs(u);
                count++;
            }
        }
        cout << count << "\n";
        if(t > 0) cout << "\n";
        
    }
}