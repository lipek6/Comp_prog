#include<bits/stdc++.h>
#define UNVISITED 1e9
using namespace std;

int n, k, d;
int amount_needed_roads = 0;
vector<bool> is_needed_road;

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
            
            amount_needed_roads++;
            is_needed_road[road_number] = true;

            dist[adjacent_city] = dist[current_city] + 1;
            q.push(adjacent_city);
        }
    }
}



int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> d;
    
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

    is_needed_road.assign(n+1, false);
    
    FindDistance(p, AL, dist);

    cout << (n-1) - amount_needed_roads << "\n";
 
    for(int i = 1; i <= (n-1); i++)
    {
        if(!is_needed_road[i]) cout << i << " ";
    } 

    cout << "\n";
}