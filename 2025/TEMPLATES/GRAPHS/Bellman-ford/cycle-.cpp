#include<bits/stdc++.h>
#define INF 1e18
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes, edges, queries, source;    
    while(true)
    {
        cin >> nodes >> edges >> queries >> source;
        if((nodes == 0) && (edges == 0) && (queries == 0) && (source == 0)) break;

        vector<vector<pair<int,long long>>> AL(nodes);

        for(int i = 0; i < edges; i++)
        {
            int node1, node2; long long weight; cin >> node1 >> node2 >> weight;

            AL[node1].push_back({node2, weight});
        }

        // Bellman-ford algorithm
        vector<long long> dist(nodes, INF);             
        vector<int> parent(nodes); iota(parent.begin(), parent.end(), 0);
        dist[source] = 0;
        
        for(int sweep = 0; sweep < nodes - 1; sweep++)                              // We execute at most V - 1 sweeps to find the answer, because the maximum distance between any two nodes should be at most V - 1, otherwiser there is a cycle
        {
            bool modified = false;                                                  // If we run the sweep and don't modify any distance, that means that we found the answer   
            for(int current_node = 0; current_node < nodes; current_node++)         // Now, on each sweep, we check and try to relax each node of the graph. We do that by looking on the nodes conected to this current node and comparing the distance on the vector with the distance we can get now
            {
                if(dist[current_node] == INF) continue;                             // If the current node has a distance of INFINITY, there is no way that using it as a root can improve the distance of any other node

                long long accumulated_weight = dist[current_node];
                
                for(auto& [adjacent_node, local_weight] : AL[current_node])
                {
                    long long new_weight = accumulated_weight + local_weight;
                    long long old_weight = dist[adjacent_node];

                    if(new_weight < old_weight)
                    {
                        dist[adjacent_node] = new_weight;
                        parent[adjacent_node] = current_node;
                        modified = true;
                    }
                }
            }
            if(!modified) break;
        }

        bool hasNegativeCycle = false;
        vector<bool> in_negative_cycle(nodes, false);
        queue<int> negative_queue;

        // We will do one more sweep, if we can improve something, that means that we have a negative cycle, because getting a path greater than V - 1 gives us a better answer, and that is only possible if there is a negative cycle in the graph
        for(int current_node = 0; current_node < nodes; current_node++)
        {
            if(dist[current_node] == INF) continue;
            
            long long accumulated_weight = dist[current_node];

            for(auto& [adjacent_node, local_weight] : AL[current_node])
            {
                long long new_weight = accumulated_weight + local_weight;
                long long old_weight = dist[adjacent_node];

                if(new_weight < old_weight)
                {
                    if(!in_negative_cycle[current_node])
                    {
                        in_negative_cycle[adjacent_node] = true;
                        negative_queue.push(adjacent_node);
                    }
                }
            }
        }
        
        // Finding nodes reachable from the negative cycle
        while(!negative_queue.empty())
        {
            int cycle_node = negative_queue.front();
            negative_queue.pop();

            dist[cycle_node] = -INF;
            for(auto& [reached_node, w] : AL[cycle_node])
            {
                if(!in_negative_cycle[reached_node])
                {
                    in_negative_cycle[reached_node] = true;                                                                                 
                    negative_queue.push(reached_node);
                }
            }
        }

        while(queries--)
        {
            int target; cin >> target;
            
            if(dist[target] == -INF)
                cout << "-Infinity\n";
            else if(dist[target] == +INF)
                cout << "Impossible\n";
            else
                cout << dist[target] << "\n";
        }
        cout << "\n";
    }
}