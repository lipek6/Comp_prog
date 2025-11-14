#include<bits/stdc++.h>
using namespace std;

enum {BLUE = -1, PINK = -2, NONE = -3};

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, m; cin >> n >> m;
    
    vector<vector<int>> AL(n+1);
    vector<int> color(n+1, NONE);

    for(int i = 0; i < m; i++)
    {
        int v1, v2; 
        cin >> v1 >> v2;

        AL[v1].push_back(v2);
        AL[v2].push_back(v1);
    }

    // Formula for amount of pairs is (n * (n - 1)) / 2, in this case we do -m because we don't wanna count already existing pairs
    // (and edges connects two guys, that means that each edge is a pair, so we remove them)

    long long TotalAmountOfPairs = (n * (n - 1)) / 2 - m;

    queue<int> q;
    for(int source_node = 1; source_node <= n; source_node++)
    {
        if(color[source_node] != NONE) continue;
        
        long long blues = 0LL;
        long long pinks = 0LL;
    
        q.push(source_node);

        while(!q.empty())
        {
            int current_node = q.front(); q.pop();

            if(color[current_node] == NONE) color[current_node] = PINK, pinks++;

            for(int adjacent_node : AL[current_node])
            {
                if(color[current_node] == color[adjacent_node])
                {
                    cout << "0" << "\n";
                    return 0;
                }
                
                if(color[adjacent_node] != NONE) continue;
                
                if(color[current_node] == PINK) color[adjacent_node] = BLUE, blues++;
                if(color[current_node] == BLUE) color[adjacent_node] = PINK, pinks++;
                
                q.push(adjacent_node);
            }
        }

        long long UnwantedBluePairs = (blues * (blues - 1)) / 2;
        long long UnwantedPinkPairs = (pinks * (pinks - 1)) / 2;
        TotalAmountOfPairs -= (UnwantedBluePairs + UnwantedPinkPairs);

    }

    cout << TotalAmountOfPairs << "\n";

    //for(int i = 1; i <= n; i++)
    //{
    //    if(color[i] == PINK) cout << i << " = PINK" << "\n";  
    //    if(color[i] == BLUE) cout << i << " = BLUE" << "\n";
    //    if(color[i] == NONE) cout << i << " = NONE" << "\n";    
    //}
}