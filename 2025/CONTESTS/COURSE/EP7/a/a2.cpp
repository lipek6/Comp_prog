#include<bits/stdc++.h>
#define INF 1e18
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int source = 1;
    int n, m; cin >> n >> m;
    
    vector<vector<pair<int,int>>> AL(n+1);

    for(int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        AL[a].push_back({c, b});
    }
    
    queue<int> q;
    vector<long long> dist(n+1, INF);

    p.push({0, source}); dist[source] = 0;

    while(!pq.empty())
    {
        pair<long long,int> node_data = pq.top();
        long long source_distance = node_data.first;
        int current_node = node_data.second;

        pq.pop();

        if(source_distance > dist[current_node]) continue;

        for(pair<long long, int> adjacent_node_data : AL[current_node])
        {
            long long connection_distance = adjacent_node_data.first;
            int adjacent_node = adjacent_node_data.second;

            long long old_distance = dist[adjacent_node];
            long long new_distance = dist[current_node] + connection_distance;

            if(old_distance < new_distance) continue;

            dist[adjacent_node] = new_distance;
            pq.push({new_distance, adjacent_node});
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
}