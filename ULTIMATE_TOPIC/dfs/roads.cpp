#include<bits/stdc++.h>
using namespace std;

// We will use a Adjacent list to store the graph
vector<vector<int>> AL;        // Not using a pair because there is no weight in this graph


// We will use deep-first search to traverse the graph
vector<bool> visited;
void dfs(int u)
{
    visited[u] = true;
    for(int i = 0; i < AL[u].size(); i++)
    {
        int neighbor = AL[u][i];
        if(visited[neighbor] == false)
        {
            dfs(neighbor);
        }
    }
}

int main (void)
{
    int v, e; cin >> v >> e;
    AL.resize(v + 1);
    visited.resize(v + 1);
    fill(visited.begin(), visited.end(), 0);

    for(int i = 0; i < e; i++)
    {
        int a, b; cin >> a >> b;      // Vertex a and b are connected
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    dfs(1);
    int disconnections = 0;
    vector<pair<int,int>> to_connect;

    for(int i = 1; i < visited.size(); i++)
    {
        if(visited[i] == false)
        {
            dfs(i);
            disconnections++;
            to_connect.push_back({i - 1, i});
        }
    }
    cout << disconnections << "\n";
    for(int i = 0; i < disconnections; i++) cout << to_connect[i].first << " " << to_connect[i].second << "\n";
}