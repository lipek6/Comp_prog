#include<bits/stdc++.h>
using namespace std;


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;

    vector<vector<pair<long long, long long>>> AL(n+1);

    for(int i = 0; i < m; i++)
    {
        int a, b; long long c; cin >> a >> b >> c;
        AL[a].push_back({c, b});
    }

    vector<long long> dist(n+1, LLONG_MAX);
    vector<bool> visited(n+1, false);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    pq.push({0LL, 1});
    dist[1] = 0LL;

    while(!pq.empty())
    {
        auto [srcWeight, srcCity] = pq.top();
        pq.pop();

        if(srcWeight > dist[srcCity]) continue;
        if(visited[srcCity]) continue;

        for(auto& [adjWeight, adjCity] : AL[srcCity])
        {
            if(dist[adjCity] < adjWeight + dist[srcCity]) continue;

            dist[adjCity] = adjWeight + dist[srcCity];
            pq.push({dist[adjCity], adjCity});
        }
        visited[srcCity] = true;
    }

    for(int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    cout << "\n";
}