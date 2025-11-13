#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q; cin >> n >> m >> q;
    
    vector<vector<pair<long long, long long>>> AL(n+1);
    
    for(int i = 0; i < m; i++)
    {
        long long c;
        int a, b; cin >> a >> b >> c;
        AL[a].push_back({b, c});
        AL[b].push_back({a, c});
    }
    
    int source = 1;
    int target = n;
    
    vector<bool> visited(n+1, false);
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



    while(q--)
    {
        cin >> source >> target;			min_dist[a][b] = 0;

		} else if (min_dist[a][b] == BIG) {
        if(dist[target] == LLONG_MAX) cout << "-1" << "\n";
        else cout << dist[target] << "\n";
    }
}
