#include<bits/stdc++.h>
using namespace std;

enum {UNVISITED = 0, EXPLORED = 1, VISITED = 2};

vector<vector<int>> AL;
vector<int> dfs_states;
vector<int> dfs_parents;
vector<int> cycle_path;


void DfsCycleCheck (int start_node)
{




}



// Cycle detection
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    
    AL.resize(n+1);
    dfs_states.resize(n+1, UNVISITED);
    dfs_parents.resize(n+1, 0);
    for(int i = 0; i < m; i++)
    {
        int city1, city2;
        cin >> city1 >> city2;
        AL[city1].push_back(city2);
        AL[city2].push_back(city1);
    }


    for(int i = 1; i <= n; i++)
    {
        cycle_path.clear();
        DfsCycleCheck(i);
        if(cycle_path.size() >= 3)
        {
            break;
        }
    }        

    if(cycle_path.size() < 3)
    {
        cout << "IMPOSSIBLE" << "\n";
        return 0;
    }

    cycle_path.push_back(cycle_path[0]);

    cout << cycle_path.size() << "\n";
    for(int i = 0; i < cycle_path.size(); i++)
    {
        cout << cycle_path[i] << " ";
    }
    cout << "\n";
}