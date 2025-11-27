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
        AL[a_room].push_back({tunnel_score, b_room});
    }
    
    long long score = 0;

    vector<long long> dist_score(rooms + 1, -INF);
    vector<bool> visited(rooms + 1, false);
    priority_queue<pair<int,int>> max_heap;
    max_heap.push({score, 1});
    long long max_score = -INF;

    while(!max_heap.empty())
    {
        auto [curr_score, curr_room] = max_heap.top();
        max_heap.pop();

        if(dist_score[curr_room] > curr_score) continue;         // Trash on the heap
        if(visited[curr_room]) continue;

        for(auto [adj_score, adj_room] : AL[curr_room])
        {
            long long new_score = adj_score + curr_score;

            if(new_score < dist_score[adj_room]) continue;

            dist_score[adj_room] = new_score;
            max_score = max(max_score, new_score);
            max_heap.push({adj_score, adj_room});
        }
        visited[curr_room] = true;
    }

    if(dist_score[rooms] == -INF || max_score > dist_score[rooms])
        dist_score[rooms] = -1;
        
    cout << dist_score[rooms] << "\n";
}