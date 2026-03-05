#include<bits/stdc++.h>
#define UNVISITED 1e18
using namespace std;


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;

    vector<long long> dist(n+1, UNVISITED);
    vector<vector<pair<int,int>>> AL(n+1);

    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        
        AL[a].push_back({w, b});
        AL[b].push_back({w, a});
    }


    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    dist[1] = 0; pq.push({dist[1], 1});

    vector<long long> parent(n+1, UNVISITED);
    while(!pq.empty())
    {
        pair<long long,int> node_data = pq.top();
        pq.pop();
        
        int connected_weight = node_data.first;
        int connected_node = node_data.second;

        if(connected_weight > dist[connected_node]) continue;
        
        for(pair<long long, int> adj_node_data : AL[connected_node])
        {
            long long adj_weigth = adj_node_data.first;
            int adj_node   = adj_node_data.second;

            long long old_weight = dist[adj_node];
            long long new_weight = dist[connected_node] + adj_weigth;

            if(old_weight < new_weight) continue;

            dist[adj_node] = new_weight;
            pq.push({dist[adj_node], adj_node});
            parent[adj_node] = connected_node;
        }
    }

    if(dist[n] == UNVISITED)
    {
        cout << "-1" << "\n";
        return 0;
    }

    vector<int> path;
    int node = n;
    while(parent[node] != UNVISITED)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);


    for(int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << "\n";
}