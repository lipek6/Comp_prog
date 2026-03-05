#include<bits/stdc++.h>
using namespace std;
#define UNVISITED -1

vector<vector<int>> AL;
vector<int> dist;

// If we want the maximum distance between two nodes, we just need to run a BFS :)
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    
    AL.resize(n+1);
    
    for(int i = 0; i < m; i++)
    {
        int guy1, guy2;
        cin >> guy1 >> guy2;
        
        AL[guy1].push_back(guy2);
        AL[guy2].push_back(guy1);
    }
    
    
    int k = 0;
    for(int i = 1; i <= n; i++) // Run a BFS on each node to find the maximum distance
    {
        dist.assign(n+1, UNVISITED);
        queue<int> q; 
        q.push(i);
        dist[i] = 0;

        while(!q.empty())
        {
            int source_node = q.front();
            q.pop();

            for(int adjacent_node : AL[source_node])
            {
                if(dist[adjacent_node] == UNVISITED)
                {
                    dist[adjacent_node] = dist[source_node] + 1;
                    q.push(adjacent_node);
                    k = max(k, dist[adjacent_node]);
                }
            }
        }

        // Check if it is impossible to connect two people
        if(i == 1)
        {
            for(int j = 1; j <= n; j++)
                {
                    if(dist[j] == UNVISITED)
                    {
                        cout << "=[" << "\n";
                        return 0;
                    }
                }
        }
    }

    cout << "=] " << k << "\n";

}