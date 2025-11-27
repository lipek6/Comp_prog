#include<bits/stdc++.h>
#define INF 1e18
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int rooms, tunnels; cin >> rooms >> tunnels;
    vector<vector<pair<int,int>>> AL(rooms + 1);

    for(int i = 1; i <= tunnels; i++)
    {
        int a_room, b_room, tunnel_score; cin >> a_room >> b_room >> tunnel_score;
        AL[a_room].push_back({b_room, tunnel_score});
    }
    
    vector<long long> dscore(rooms + 1, -INF);
    dscore[1] = 0;

    for(int sweep = 0; sweep < rooms - 1; sweep++)
    {
        bool modified = false;
        for(int root_node = 1; root_node <= rooms; root_node++)
        {
            if(dscore[root_node] == -INF) continue;

            long long accumulated_score = dscore[root_node];
            for(auto& [adj_node, adj_score] : AL[root_node])
            {
                long long old_score = dscore[adj_node];
                long long new_score = accumulated_score + adj_score;

                if(new_score > old_score)
                {
                    dscore[adj_node] = new_score;
                    modified = true;
                }
            }
        }
        if(!modified) break;
    }

    vector<bool> affected_by_cycle(rooms+1, false);
    queue <int>  to_check_affection;
    for(int root_node = 1; root_node <= rooms; root_node++)
    {
        if(dscore[root_node] == -INF) continue;

        long long accumulated_score = dscore[root_node];
        for(auto& [adj_node, adj_score] : AL[root_node])
        {
            long long new_score = accumulated_score + adj_score;
            long long old_score = dscore[adj_node];

            if(new_score > old_score)
            {
                affected_by_cycle[adj_node] = true;
                to_check_affection.push(adj_node);
                break;
            }
        }
    }

    while(!to_check_affection.empty())
    {
        int affected_node = to_check_affection.front();
        to_check_affection.pop();

        dscore[affected_node] = INF;
        
        for(auto& [maybe_affected_node, w] : AL[affected_node])
        {
            if(!affected_by_cycle[maybe_affected_node])
            {
                affected_by_cycle[maybe_affected_node] = true;
                to_check_affection.push(maybe_affected_node);
            }
        }
    }


    if(dscore[rooms] == INF || affected_by_cycle[rooms]) dscore[rooms] = -1;
    
    cout << dscore[rooms] << "\n";
}