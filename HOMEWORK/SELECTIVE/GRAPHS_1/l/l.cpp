#include<bits/stdc++.h>
#define UNVISITED 1e9
using namespace std;

// Heatmap BFS to find the minimum distance of all police estations to each city
void FindDistance (vector<int> &p, vector<vector<pair<int,int>>> &AL, vector<int> &dist)
{
    queue<int> q; 
    for(int station : p)
    {
        q.push(station);
        dist[station] = 0;
    }

    while(!q.empty())
    {
        int current_city = q.front(); q.pop();
        
        for(auto &[adjacent_city, road_number] : AL[current_city])
        {
            if(dist[adjacent_city] != UNVISITED) continue;
            
            dist[adjacent_city] = dist[current_city] + 1;
            q.push(adjacent_city);
        }
    }
}

int FindShutableRoads(vector<vector<pair<int,int>>> &AL, vector<int> &dist, int &n, vector<int> &shutable_roads)
{
    int amount_shutable_roads = 0;
    
    for(int current_city = 1; current_city <= n; current_city++)
    {
        for(auto &[adjacent_city, road_number] : AL[current_city])
        {
            if(dist[adjacent_city] == dist[current_city])
            {
                amount_shutable_roads++;
                shutable_roads.push_back(road_number);
            }
        }
    }
    return amount_shutable_roads;
}



int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, d; cin >> n >> k >> d;
    
    vector<int> p(k);
    vector<vector<pair<int,int>>> AL(n+1); // Second element of the pair is the number of the road, not it's size, all sizes are 1 km
    vector<int> dist(n + 1, UNVISITED);

    for(int i = 0; i < k; i++) cin >> p[i];
    for(int i = 1; i <= n - 1; i++)
    {
        int city1, city2;
        cin >> city1 >> city2;
        AL[city1].push_back({city2, i});
        AL[city2].push_back({city1, i});
    }

    vector<int> shutable_roads;
    
    FindDistance(p, AL, dist);
 
    int amount_shutable_roads = FindShutableRoads(AL, dist, n, shutable_roads);

    cout << amount_shutable_roads << "\n";
    for(int road : shutable_roads) cout << road << " ";

    cout << "\n";
}