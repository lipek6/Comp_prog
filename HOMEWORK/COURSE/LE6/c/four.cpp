#include<bits/stdc++.h>
using namespace std;

enum { UNVISITED = -1, VISITED = -2, EXPLORED = -3 };

vector<vector<int>> AL;
vector<int> dfs_num;
vector<int> dfs_parent;
vector<int> cycle;

void cycleCheck (int u)
{
    dfs_num[u] = EXPLORED;

    for(int i = 0; i < AL[u].size(); i++)
    {    
        int v = AL[u][i];
        
        if(dfs_num[v] == UNVISITED)
        {
            dfs_parent[v] = u;
            cycleCheck(v);
        }
        else if(dfs_num[v] == EXPLORED)
        {
            if(v != dfs_parent[u]) // Cycle found
            {
                cycle.push_back(v);
                
                int j = u;
                while(j != v)
                {
                    cycle.push_back(j);
                    j = dfs_parent[j];
                }
                cycle.push_back(v);

                cout << cycle.size() << "\n";
                for(int i = 0; i < cycle.size(); i++)
                {
                    cout << cycle[i] << " ";
                }
                cout << "\n";
                exit(0);
            }
        }
    }
    dfs_num[u] = VISITED;
}


// We need to create a cycle between the given cities using the given roads
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m; cin >> n >> m;

    dfs_num.assign(n+1, UNVISITED);
    dfs_parent.assign(n+1, -1);
    AL.resize(n+1);
    
    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    for(int u = 1; u <= n; u++)
    {
        if(dfs_num[u] == UNVISITED)
            cycleCheck(u);

    }
    cout << "IMPOSSIBLE" << "\n";
}