#include<bits/stdc++.h>
using namespace std;

// Possible states of the nodes
enum {UNVISITED = -1, VISITED = -2};

// Adjacency list to store the connections of the graph nodes
vector<vector<int>> AL;

// Vector to store the state of the nodes()
vector<int> dfs_num;

// Funtion to run a deep-first search on the given graph
void dfs (int u)
{
    dfs_num[u] = VISITED;
    for(int v = 0; v < AL[u].size(); v++)
    {
        if(AL[u][v] == UNVISITED)
            dfs(AL[u][v]);
    }
}

// Vector to store the topologicaly sorted graph
vector<int> topologicaly_sorted;

// Funtion to topologicaly sort a graph with a deep-first search implementation
void topo_sort(int u)
{
    dfs_num = VISITED;
    for(int v = 0; v < AL[u].size(); v++)
    {
        if(AL[u][v] == UNVISITED)
            topo_sort(AL[u][v]);
    }
    topologicaly_sorted.push_back(u);
}



int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V = 12; // Number of vertexs

    dfs_num.assign(V, UNVISITED);
    topologicaly_sorted.clear();
    for(int u = 0; u < V; u++)
    {
        if(dfs_num[u] == UNVISITED)
            topo_sort(u);   
    }
    reverse(topologicaly_sorted.begin(), topologicaly_sorted.end()); // Reversing to make it on the right order

    for(int i = 0; i < topologicaly_sorted.size(); i++)
    {
        cout << topologicaly_sorted[i] << " ";
    }
    cout << "\n";
}