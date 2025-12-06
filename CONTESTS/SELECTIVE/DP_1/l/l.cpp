#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

vector<vector<pair<int,int>>> AL;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int bitsize = 2 * 1e5;
    int N, M, K; cin >> N >> M >> K;
    AL.resize(N+1);

    for(int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        AL[a].push_back({c, b});
        AL[b].push_back({c, a});
    }
    vector<bitset<bitsize>> bitmask(N+1);
    vector<vector<int>> tp_costs(N+1, vector<int>(K));
    for(int i = 1; i <= N; i++)
    {
        int T; cin >> T;

        for(int j = 0; j < T; j++)
        {
            int type, cost; cin >> type >> cost;
            bitmask[i] = type | bitmask[i];
            tp_costs[i][type] = cost;
        }
    }

    for(int i = 1; i <= N; i++)
    {
        bitset<bitsize > avl_tp;
        for(int j = 1; j <= N; j++)
        {
            avl_tp = bitmask[i] & bitmask[j];
            for(int k = 0; K < K; k++)
            {
                if(avl_tp[k])
                {
                    AL[i].push_back({tp_costs[i][k], j});
                }
            }
        }        
    }



    int source = 1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
    vector<int> dist(N+1, INF);
    heap.push({0, source});
    dist[source] = 0;

    while(!heap.empty())
    {
        auto [current_distance, current_node] = heap.top();
        heap.pop();

        if(dist[current_node] < current_distance) continue; // Case of trash on the heap

        for(auto& [local_distance, ajdacent_node] : AL[current_node])
        {
            int new_distance = dist[current_node] + local_distance; 
            
            if(dist[ajdacent_node] < new_distance) continue; // Case of trash on the heap

            dist[ajdacent_node] = new_distance;
            heap.push({new_distance, ajdacent_node});
        }
    }
}