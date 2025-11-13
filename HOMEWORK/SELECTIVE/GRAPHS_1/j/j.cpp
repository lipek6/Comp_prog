#include<bits/stdc++.h>
using namespace std;

enum {UNVISITED = 0, EXPLORED = 1, VISITED = 2};

vector<vector<int>> AL;
vector<int> dfs_visited;
vector<int> courses_path;

void dfs (int source_node)
{   
    dfs_visited[source_node] = EXPLORED;
    
    for(int adjacent_node : AL[source_node])
    {        
        if(dfs_visited[adjacent_node] == UNVISITED)
        {
            dfs(adjacent_node);
        }
        if(dfs_visited[adjacent_node] == EXPLORED)
        {
            cout << "IMPOSSIBLE" << "\n";
            exit(0);
        }
    }
    courses_path.push_back(source_node);
    dfs_visited[source_node] = VISITED;
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    AL.resize(n+1);
    dfs_visited.assign(n+1, UNVISITED);

    for(int i = 0; i < m; i++)
    {
        int course1, course2; 
        cin >> course1 >> course2;
        
        AL[course1].push_back(course2); 
    }

    for(int i = 1; i <= n; i++)
    {
        if(dfs_visited[i] == UNVISITED)
            dfs(i);
    }

    for(int i = courses_path.size() - 1; i >= 0; i--)
    {
        cout << courses_path[i] << " ";
    }

    cout << "\n";
}