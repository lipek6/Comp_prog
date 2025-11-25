#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int total_dist = 0;
int intersections, streets, friends;

int djakastra(int source, auto& AL, auto& friend_house);

// Home is at intersection number one and camping site is at intersection number N
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    int case_num = 0;
    while(tc--)
    {
        case_num++;

        cin >> intersections >> streets >> friends;
        
        total_dist = 0;
        vector<vector<pair<int,int>>> AL(intersections + 1);
        vector<int> friend_house(friends);
                
        for(int i = 0; i < streets; i++)
        {
            int pt1, pt2, len;
            cin >> pt1 >> pt2 >> len;
            
            AL[pt1].push_back({len, pt2});
            AL[pt2].push_back({len, pt1});
        }
        
        for(int i = 0; i < friends; i++) cin >> friend_house[i];
        
        int next_friend = djakastra(1, AL, friend_house);
        
        while(next_friend != -1)
        {
            next_friend = djakastra(next_friend, AL, friend_house);
        }
        
        cout << "Case " << case_num << ": " << total_dist << "\n";
    }
}

int djakastra(int source, auto& AL, auto& friend_house)
{
    vector<int> parent(intersections + 1, INF);
    vector<int> dist(intersections + 1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;

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
            parent[ajdacent_node] = current_node;
            heap.push({new_distance, ajdacent_node});
        }
    }

    int i = 0;
    int idx = 0;
    int next_friend = 0;
    for(; i < friend_house.size(); i++)
    {
        if(friend_house[i] != -1)
        {
            if(dist[friend_house[i]] < dist[next_friend])
            {
                next_friend = friend_house[i];
                idx = i;
            }
        }
    }

    if(next_friend == 0) return -1;

    total_dist += dist[next_friend];
    friend_house[idx] = -1;
    return next_friend;
}