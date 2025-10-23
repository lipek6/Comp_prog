#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int s;      // Source node
    cin >> s;

    vector<int> dist(v, INFINITY); dist[s] = 0; // The distance vector stores the distance(layers) between the source node and the current node, but also stores the info if it was or was not visited before
    queue<int> q; q.push(s);

    while(!q.empty())
    { 
        int u = q.front();  q.pop();
        for(int i = 0; i < AL[u].size(); i++)
        {
            int current_neighbor = AL[u][i];
            if (dist[current_neighbor] != INFINITY) continue;
            dist[current_neighbor] = dist[u] + 1;
            q.push(current_neighbor);
        }
    }
}