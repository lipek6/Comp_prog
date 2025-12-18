#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int source = 1;
    int n, m; cin >> n >> m;
    
    vector<vector<pair<long long, long long>>> AL(n+1);
    vector<bool> visited(n+1, false);
    for(int i = 0; i < m; i++)
    {
        long long c;
        int a, b; cin >> a >> b >> c;
        AL[a].push_back({b, c});
    }
    
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    vector<long long> dist(n+1, LLONG_MAX);

    pq.push({0LL, source}); dist[source] = 0;

    while(!pq.empty())
    {
        auto [source_distance, current_node] = pq.top();
        pq.pop();

        if(source_distance > dist[current_node]) continue;
        
        if(visited[current_node] == true) continue;

        for(auto &[adjacent_node, connection_distance] : AL[current_node])
        {
            long long new_distance = dist[current_node] + connection_distance;

            if(dist[adjacent_node] < new_distance) continue;

            dist[adjacent_node] = new_distance;
            pq.push({new_distance, adjacent_node});
        }
        visited[current_node] = true;
    }

    for(int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << "\n";
}