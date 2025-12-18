#include<bits/stdc++.h>
using namespace std;



int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t; cin >> t;
    
    int counter = 1;
    while(t--)
    {
        int n, m, S, T; cin >> n >> m >> S >> T;

        vector<vector<pair<int,int>>> AL(m+1);
        
        for(int i = 0; i < m; i++)
        {
            int u, v, w; cin >> u >> v >> w;
            AL[u].push_back({v, w});
            AL[v].push_back({u, w});
        }

        vector<int> distance(n, 1e9); distance[S] = 0;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
        pq.emplace(0, S);

        while(!pq.empty())
        {
            auto [d, u] = pq.top(); pq.pop();
            if(d > distance[u]) continue;
            for(auto &[v, w] : AL[u])
            {
                if(distance[u] + w >= distance[v]) continue;
                distance[v] = distance[u] + w;
                pq.emplace(distance[v], v);
            }
        }

        if(distance[T] == 1e9)
            cout << "Case #" << counter << ": " << "unreachable" << "\n";
        else
            cout << "Case #" << counter << ": " << distance[T] << "\n";

        counter++;
    }
    
}