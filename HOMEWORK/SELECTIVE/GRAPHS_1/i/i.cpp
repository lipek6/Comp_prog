#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> EL;
string result = "";
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
        
        if(a > b)
        {
            int t = a; a = b; b = t;
        }

        EL.push_back({a, b});
    }

    vector<vector<int>> problems(m);
    color.assign(m, UNDEFINED_ROAD); // color of each pair of nodes
        
    for(int i = 0; i < EL.size(); i++)
    {
        int road_start = EL[i].first;
        int road_end   = EL[i].second;

        for(int j = i+1; j < EL.size(); j++)
        {
            int other_start = EL[j].first;
            int other_end   = EL[j].second;

            bool other_start_inside = (other_start > road_start && other_start < road_end); // Other road starts inside the range of the road
            bool other_end_inside   = (other_end   > road_start && other_end   < road_end);

            if(other_start_inside != other_end_inside)
            {
                problems[]
            }
        }
    }

    cout << result << "\n";
}