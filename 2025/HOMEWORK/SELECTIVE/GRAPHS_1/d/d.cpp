#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<int> colors;

bool bfs(int start_node)
{
    queue<int> q;
    q.push(start_node);
    while(!q.empty())
    {
        int source_node = q.front();
        q.pop();
        if(colors[source_node] == 0) colors[source_node] = 1;
        for(int adjacent_node : AL[source_node])
        {
            if(colors[adjacent_node] == colors[source_node])
            {
                return false;
            }
            else if(colors[adjacent_node] == 0)
            {
                if (colors[source_node] == 1)
                    colors[adjacent_node] = 2;
                else
                    colors[adjacent_node] = 1;
                q.push(adjacent_node);
            }
        }
    }
    return true;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    
    AL.resize(n+1);
    colors.resize(n+1, 0);

    // Building an adjacency list to represent the given graph
    for(int i = 0; i < m; i++)
    {
        int guy1, guy2; cin >> guy1 >> guy2;
        AL[guy1].push_back(guy2);
        AL[guy2].push_back(guy1);
    }

    // Running BFSs to color the graph
    for(int i = 1; i <= n; i++)
    {
        if(colors[i] == 0) 
        {
            if(bfs(i) == false)
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << colors[i] << " ";
    }
    cout << "\n";
}