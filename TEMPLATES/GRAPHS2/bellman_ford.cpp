#include<bits/stdc++.h>
#define INF 1e18
using namespace std;

vector<long long> dist;
vector<int> parents;


void bellman_ford(int source, int nodes_amount, vector<vector<pair<int, long long>>>& AL);
int find_negative_cycle(int nodes_amount, vector<int>& negative_cycle, vector<vector<pair<int, long long>>>& AL);

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes_amount, edges_amount; cin >> nodes_amount >> edges_amount;
    vector<vector<pair<int, long long>>> AL(nodes_amount + 1);
    parents.assign(nodes_amount + 1, -1);
    dist.assign(nodes_amount + 1, INF);
    
    for(int i = 1; i <= edges_amount; i++)
    {
        int node1, node2; long long length; cin >> node1 >> node2 >> length;

        AL[node1].push_back({node2, length});
    }

    bellman_ford(0, nodes_amount, AL);

    vector<int> negative_cycle;
    
    int cycle_start_point = find_negative_cycle(nodes_amount, negative_cycle, AL);
    if(cycle_start_point != -1)
    {
        vector<int> print_buffer;

        cout << "YES\n";
        
        for(int i = 0; i < nodes_amount; i++) 
        {
            cycle_start_point = parents[cycle_start_point];
        }
    
        int node = parents[cycle_start_point];

        print_buffer.push_back(cycle_start_point);
        while(node != cycle_start_point)
        {
            print_buffer.push_back(node);
            node = parents[node];
        }
        print_buffer.push_back(cycle_start_point);
        reverse(print_buffer.begin(), print_buffer.end());

        for(int print_node : print_buffer) cout << print_node << " ";
        cout << "\n";         
    }
    else
    {
        cout << "NO\n";
    }
}

void bellman_ford(int source, int nodes_amount, vector<vector<pair<int, long long>>>& AL)
{
    parents[source] = source;
    dist[source] = 0;

    for(int sweep = 0; sweep < nodes_amount - 1; sweep++)
    {
        bool modified = false;
        for(int root_node = 1; root_node <= nodes_amount; root_node++)
        {
            long long root_length = dist[root_node];
            for(int adj_idx = 0; adj_idx < AL[root_node].size(); adj_idx++)
            {
                long long adj_length = AL[root_node][adj_idx].second;
                int adj_node = AL[root_node][adj_idx].first;

                long long new_length = root_length + adj_length;
                long long old_length = dist[adj_node];
                
                if(new_length < old_length)
                {
                    parents[adj_node] = root_node;
                    dist[adj_node]    = new_length;
                    modified          = true;
                }
            }
        }
        if(!modified) break;
    }
}

int find_negative_cycle(int nodes_amount, vector<int>& negative_cycle, vector<vector<pair<int, long long>>>& AL)
{    
    for(int root_node = 1; root_node <= nodes_amount; root_node++)
    {
        long long root_length = dist[root_node];
        for(auto [adj_node, adj_length] : AL[root_node])
        {
            long long new_length = root_length + adj_length;
            long long old_length = dist[adj_node];
            
            if(new_length < old_length)
            {
                parents[adj_node] = root_node;
                dist[adj_node] = new_length;
                return adj_node;
            }
        }
    }
    return -1;
}