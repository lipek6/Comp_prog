#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;

// Separate all pupills into two teens without friends together, classic bipartite graph problem
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b; cin >> n >> m;
    
    AL.resize(n+1);
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);     
    }

    vector<int> color(n+1, 0);
    queue<int> q; q.push(1);

    for(int ustart = 1; ustart <= n; ustart++)  // Loop to run into the others CCs
    {
        if(color[ustart] == 0)
        {
            color[ustart] = 1;
            q.push(ustart);
        }

        while(!q.empty())
        {
            int u = q.front(); q.pop();
            for(int i = 0; i < AL[u].size(); i++)
            {
                int v = AL[u][i];
                if(color[v] == 0)
                {
                    color[v] = 3 - color[u];
                    q.push(v);
                }
                else if(color[v] == color[u])
                {
                    cout << "IMPOSSIBLE" << "\n";
                    return 0;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if (color[i] == 0) color[i] = 1; 
        cout << color[i] << " ";
    }
    cout << "\n";
}