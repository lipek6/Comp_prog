#include<bits/stdc++.h>
#define INF 1e18
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes, roads; cin >> nodes >> roads;

    vector<vector<pair<int,int>>> AL(nodes + 1);
    vector<int> red_time  (nodes + 1);
    vector<int> green_time(nodes + 1);

    for(int i = 1; i <= nodes; i++) cin >> red_time[i] >> green_time[i]; 
    
    for(int i = 1; i <= roads; i++)
    {
        int node1, node2, distance; cin >> node1 >> node2 >> distance;

        AL[node1].push_back({distance, node2});
        AL[node2].push_back({distance, node1});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> heap;
    vector<long long> dist(nodes + 1, INF);
    heap.push({0, 1});
    dist[1] = 0;
    
    while(!heap.empty())
    {
        auto [accumulated_dist, current_node] = heap.top();
        heap.pop();
        
        if(dist[current_node] < accumulated_dist) continue;
        if(current_node == nodes) break;

        for(auto& [local_distance, adjacent_node] : AL[current_node])
        {
            long long new_distance = accumulated_dist + local_distance;

            if(adjacent_node != nodes)                                                      // Check if we aren't on the last node
            {
                int red   = red_time[adjacent_node];
                int green = green_time[adjacent_node];
                
                long long modular_time = new_distance % (red + green);                      // Finding where on the color cycle it is
                
                if(modular_time >= red) new_distance += ((red + green) - modular_time);     // Fell on green zone
            }

            if(new_distance > dist[adjacent_node]) continue;
            
            dist[adjacent_node] = new_distance;            
            heap.push({new_distance, adjacent_node});
        }
    }
    cout << dist[nodes] << "\n";
}