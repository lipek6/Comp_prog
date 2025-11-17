#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;

    vector<vector<long long>> cost_matrix(n+1, vector<long long>(n+1));
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> cost_matrix[i][j];
        }
    }

    int removable_edges = 0;

    for(int origin = 1; origin <= n; origin++)
    {
        for(int destiny = origin + 1; destiny <= n; destiny++)
        {
            bool is_removable = false;
            for(int route_stop = 1; route_stop <= n; route_stop++)
            {
                if(route_stop == origin || route_stop == destiny) continue; // Direct path

                long long indirect_cost = cost_matrix[origin][route_stop] + cost_matrix[route_stop][destiny];
                long long direct_cost = cost_matrix[origin][destiny];

                if(indirect_cost < direct_cost)
                {
                    cout << "-1\n";
                    return 0;
                }

                if(indirect_cost == direct_cost)
                {
                    is_removable = true;
                    break;
                }
            }
            if(is_removable)removable_edges++;
        }
    }
    cout << removable_edges << "\n";
}