#include<bits/stdc++.h>
#define UNVISITED -1
#define INF 1e18
using namespace std;

int n, m; 

struct EDGE
{
    int       destiny;        // Node that it geos to
    long long capacity;       // Total capacity
    long long flow;           // Current flow

    EDGE(int dest, long long cap, long long f) : destiny(dest), capacity(cap), flow(f) {} 
};

class max_flow
{
private:
    int V;
    vector<EDGE> EL;
    vector<vector<int>> AL;
    vector<int> distance;
    vector<pair<int, int>> parent;

    bool BFS (int source, int target)
    {
        distance.assign(V, UNVISITED); distance[source] = 0;
        queue<int> q; q.push({source});
        parent.assign(V, {UNVISITED, UNVISITED});
        
        while(!q.empty())
        {
            int current_node = q.front(); q.pop();
            if(current_node == target) break;

            for(auto &idx : AL[current_node])
            {
                auto &[adjacent_node, edge_capacity, edge_flow] = EL[idx];
                
                if((edge_capacity - edge_flow > 0) && (distance[adjacent_node] == UNVISITED))
                {
                    distance[adjacent_node] = distance[current_node] + 1;
                    q.push(adjacent_node);
                    parent[adjacent_node] = {current_node, idx};
                }
            }
        }
        bool reached_target = distance[target] != UNVISITED;
        return reached_target;
    }

    long long send_one_flow (int source, int target, long long flow = INF)
    {
        if(source == target) return flow;

        auto &[previous_node, idx] = parent[target];
        auto &edge_capacity        = EL[idx].capacity;
        auto &edge_flow            = EL[idx].flow;
        
        long long pushed_flow = send_one_flow(source, previous_node, min(flow, edge_capacity - edge_flow));
        edge_flow += pushed_flow;
        
        auto &reversed_flow = EL[idx^1].flow;
        reversed_flow -= pushed_flow;
        
        return pushed_flow;
    }

public:
    max_flow(int initialV) : V(initialV)
    {
        EL.clear();
        AL.assign(V, vector<int>());
    }

    void add_edge(int origin_node, int destiny_node, long long weight, bool directed = false)
    {
        if(origin_node == destiny_node) return;
        
        EL.emplace_back(destiny_node, weight, 0); // origin_node -> destiny_node, capacity = weight, flow = 0
        AL[origin_node].push_back(EL.size() - 1);
        
        EL.emplace_back(origin_node, directed ? 0 : weight, 0);
        AL[destiny_node].push_back(EL.size() - 1);
    }

    long long edmons_karp(int source, int target)
    {
        long long maximum_flow = 0;
        while(BFS(source, target))
        {
            long long flow = send_one_flow(source, target);
            
            if(flow == 0) break;

            maximum_flow += flow;
        }
        return maximum_flow;
    }

    bool is_reachable(int node)
    {
        bool can_reach = distance[node] != UNVISITED;
        return can_reach;
    }
};


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    
    max_flow BankToBay(n + 1);
    
    vector<pair<int, int>> given_edges;
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        
        given_edges.push_back({a, b});

        BankToBay.add_edge(a, b, 1, false);
    }

    int source = 1;
    int target = n;

    // Because all the streats have weight 1, the maximum flow will be the number of streets that can be cut to make him unable to get to the bay 
    long long maximum_flow = BankToBay.edmons_karp(source, target);

    cout << maximum_flow << "\n";

    for(auto &edge : given_edges)
    {
        int origin_node  = edge.first;
        int destiny_node = edge.second;

        bool CanReachOrigin  = BankToBay.is_reachable(origin_node);
        bool CanReachDestiny = BankToBay.is_reachable(destiny_node);

        if((CanReachOrigin && !CanReachDestiny) || (!CanReachOrigin && CanReachDestiny))
            cout << origin_node << " " << destiny_node << "\n";
    }
}