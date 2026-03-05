#include<bits/stdc++.h>
using namespace std;

enum {UNVISITED = 0, EXPLORED = 1, VISITED = 2};

vector<vector<int>> AL;
vector<int> dfs_states;
vector<int> dfs_parents;
vector<int> cycle_path;

void PrintPath()
{
    cout << cycle_path.size() << "\n";
    for(int i = 0; i < cycle_path.size(); i++)
    {
        cout << cycle_path[i] << " ";
    }
    cout << "\n";

}

void DfsCycleCheck (int start_node)
{
    dfs_states[start_node] = EXPLORED;
    
    for(int adjacent_node : AL[start_node])
    {
        if(dfs_states[adjacent_node] == UNVISITED)
        {
            dfs_parents[adjacent_node] = start_node;
            DfsCycleCheck(adjacent_node);
        }
        
        if(dfs_states[adjacent_node] == EXPLORED)   // Backedge or obvious cycle
        {
            if(dfs_parents[start_node] != adjacent_node)    // If we don't have the same parent, it's not an obvious cycle, I have a backedge :)
            {
                cycle_path.push_back(adjacent_node);

                int node_iterator = start_node;
                while(node_iterator != adjacent_node)
                {
                    cycle_path.push_back(node_iterator);
                    node_iterator = dfs_parents[node_iterator];
                }

                cycle_path.push_back(adjacent_node);
                
                PrintPath();

                exit(0);
            }
        }
    }
    dfs_states[start_node] = VISITED;
}



// Cycle detection
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    
    AL.resize(n+1);
    dfs_states.resize(n+1, UNVISITED);
    dfs_parents.resize(n+1, 1);
    for(int i = 0; i < m; i++)
    {
        int city1, city2;
        cin >> city1 >> city2;
        AL[city1].push_back(city2);
        AL[city2].push_back(city1);
    }


    for(int i = 1; i <= n; i++)
    {
        if(dfs_states[i] == UNVISITED)
            DfsCycleCheck(i);
    }        

    cout << "IMPOSSIBLE" << "\n";
}