#include<bits/stdc++.h>
#define INF 1e18
using namespace std;

vector<vector<pair<long long,int>>> AL;

bool dijkstra(int source, int destiny, vector<long long>& dist, vector<long long>& parent);

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; long long L; cin >> n >> m >> L;
    long long full = L;

    AL.resize(n + 1);

    for(int i = 0; i < m; i++)
    {
        int a, b; long long c; cin >> a >> b >> c;

        AL[a].push_back({c, b});
        AL[b].push_back({c, a});
    }

    int queries; cin >> queries;
    
    
    while(queries--)
    {
        vector<long long> dist(n + 1, INF);
        vector<long long> parent(n + 1, INF);

        int source, destiny; cin >> source >> destiny;
        
        bool impossible = dijkstra(source, destiny, dist, parent);

        L = full;
        long long recharges = 0;

        if(!impossible)
        {
            vector<int> path;
            int node = destiny;
            while(parent[node] != node)
            {
                path.push_back(node);
                node = parent[node];
            } 
            path.push_back(source);
            reverse(path.begin(), path.end());

            for(int i = 1; i < path.size(); i++)
            {
                long long spent_litters = dist[path[i]] - dist[path[i-1]];

                if(L - spent_litters < 0)
                {
                    L = full;
                    recharges++;
                }

                L -= spent_litters;

                if(L < 0)
                {
                    impossible = true;
                    break;    
                }
            }
        }

        if(impossible)
        {
            cout << "-1\n";
        }
        else
        {
            cout << recharges << "\n";
        }
    }
}

bool dijkstra(int source, int destiny, vector<long long>& dist, vector<long long>& parent)
{
    priority_queue<pair<long long, long long>> heap;
    parent[source] = source;
    heap.push({0, source});
    dist[source] = 0;

    while(!heap.empty())
    {
        auto [curr_legth, curr_node] = heap.top();
        heap.pop();

        if(curr_legth > dist[curr_node]) continue;          // Trash on the heap
        
        for(auto [adj_length, adj_node] : AL[curr_node])
        {
            long long old_length = dist[adj_node];
            long long new_length = dist[curr_node] + adj_length;

            if(new_length < old_length)
            {
                dist[adj_node] = new_length;
                parent[adj_node] = curr_node;
                heap.push({new_length, adj_node});
            }
        }
    }
    if(dist[destiny] == INF)
        return true;
    return false;
}