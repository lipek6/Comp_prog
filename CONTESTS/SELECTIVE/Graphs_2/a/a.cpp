#include<bits/stdc++.h>
#define UNVISITED 1e18
using namespace std;

// The god little optimization of djkstra is a hero (VISITED VECTOR)

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    vector<bool> visited(n+1, false);
    vector<long long> nodes_weights(n + 1);
    vector<long long> dist(n+1, UNVISITED);
    vector<vector<pair<long long,int>>> AL(n + 1);

    for(int i = 1; i <= n; i++) cin >> nodes_weights[i];
    for(int i = 1; i <= m; i++)
    {
        int u, v; long long w; cin >> u >> v >> w;
        AL[u].push_back({w + nodes_weights[v], v}); // This sum can be a problem later
        AL[v].push_back({w + nodes_weights[u], u});
    }   

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[1] = 0; pq.push({dist[1], 1});

    while(!pq.empty())
    {
        auto [connected_weight, connected_node] = pq.top();
        pq.pop();

        if(connected_weight > dist[connected_node]) continue;
        if(visited[connected_node] == true) continue;
        for(auto& [adj_weigth, adj_node]  : AL[connected_node])
        {
            long long old_weight = dist[adj_node];
            long long new_weight = dist[connected_node] + adj_weigth;

            if(old_weight < new_weight) continue;

            dist[adj_node] = new_weight;
            pq.push({dist[adj_node], adj_node});
        }
        visited[connected_node] = true;
    }

    for(int i = 2; i <= n; i++) cout << dist[i] + nodes_weights[1] << " ";
    cout << "\n";
}