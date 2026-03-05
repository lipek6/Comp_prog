#include<bits/stdc++.h>
#define INF 1e18
using namespace std;


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;

    vector<vector<pair<int, long long>>> AL(n+1);
    for(int i = 1; i <= n; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;    
        AL[a].push_back({b, w});
        AL[b].push_back({a, w});
    }

    vector<long long> dist(n+1, INF);
    dist[1] = 0;

    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int current_node = q.front();
        q.pop();

        for(auto& [adjacent_node, realative_distance] : AL[current_node])
        {
            if(dist[adjacent_node] != INF) continue;

            dist[adjacent_node] = dist[current_node] + realative_distance;
            q.push(adjacent_node);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(dist[i] % 2 == 0)
            cout << "0" << "\n";
        else
            cout << "1" << "\n";
    }
}