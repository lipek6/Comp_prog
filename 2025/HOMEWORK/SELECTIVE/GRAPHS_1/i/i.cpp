#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> EL;
vector<int> color;
int n, m; 

enum {INSIDE_ROAD = 1, OUTSIDE_ROAD = 2, UNDEFINED_ROAD = 0};

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        
        // Get a and b in order
        if(a > b) swap(a, b);
        EL.push_back({a, b});
    }

    vector<vector<int>> problems_between_roads(m); // Each node is a road, a road connects to another (in this graph) if they intersect
    
    for(int i = 0; i < EL.size(); i++)
    {
        int road_start = EL[i].first;
        int road_end   = EL[i].second;
        
        for(int j = i+1; j < EL.size(); j++)
        {
            int other_start = EL[j].first;
            int other_end   = EL[j].second;
            
            // Aparantly, they only intersect each other if one starts inside the other and ends outside or starts outside and ends insde
            bool starts_inside_ends_outside = ((other_start > road_start && other_start < road_end ) && (other_end > road_end));
            bool starts_outside_ends_inside = ((other_start < road_start) && (other_end > road_start && other_end < road_end)); 
            
            if(starts_inside_ends_outside || starts_outside_ends_inside)
            {
                problems_between_roads[i].push_back(j); // Push_backing ROADS, IT'S A GRAPH OF ROADS, IS A GRAPH WHERE THE NODES ARE EDGES OF THE OTHER GRAPH AAAAAA
                problems_between_roads[j].push_back(i); // Push_backing ROADS, IT'S A GRAPH OF ROADS, IS A GRAPH WHERE THE NODES ARE EDGES OF THE OTHER GRAPH AAAAAA
            }
        }
    }
    
    color.assign(m, UNDEFINED_ROAD);
    
    queue<int> q;
    
    bool impossible = false;
    for(int i = 0; i < m; i++)
    {
        if(impossible) break;
        if(color[i] != UNDEFINED_ROAD) continue;
        
        
        q.push(i); color[i] = INSIDE_ROAD;
        while(!q.empty())
        {
            if(impossible) break;
            int road1 = q.front(); q.pop();
            
            for(int road2 : problems_between_roads[road1])
            {
                if(color[road2] == UNDEFINED_ROAD)
                {
                    if(color[road1] == INSIDE_ROAD)  color[road2] = OUTSIDE_ROAD;
                    if(color[road1] == OUTSIDE_ROAD) color[road2] = INSIDE_ROAD;
                    q.push(road2);
                }
                
                if(color[road1] == color[road2])
                {
                    impossible = true;
                    break;
                }
            }
        }
    }
    
    if(impossible)
    {
        cout << "Impossible\n";
        return 0;
    }
    else
    {
        string result = "";
        for(int road_color : color)
        {
            if(road_color == UNDEFINED_ROAD) road_color = INSIDE_ROAD;
            
            if(road_color == INSIDE_ROAD) result.append("i");
            if(road_color == OUTSIDE_ROAD)result.append("o");
        }
        
        cout << result << "\n";
    }
}