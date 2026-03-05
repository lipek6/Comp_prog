#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

enum {UNVISITED = -1, VISITED = -2};

vector<vii> AL;            // Adjacency list to represent the graph (it's a vector of vectors of pairs)
vector<int> dfs_num;       // Vector that says if a vertice was visited or not



// Executes a deep-first search (book code)
void dfs(int u) // u is the node where we will begin
{
    dfs_num[u] = VISITED;
    for (auto &[v, w] : AL[u])
        if (dfs_num[v] == UNVISITED)
            dfs(v);
}

// Executes a deep-first search (My own code. I think it's more readable)
void dfs_own(int u)
{
    dfs_num[u] = VISITED;
    for(int i = 0; i < AL[u].size(); i++)
    {
      //printf(" %d", u);
        int neighbor_node = AL[u][i].first;         // At the vector of pairs (edge informations) of the node u, iterate through the nodes that it are connected to u
        int connection_weight = AL[u][i].second;    // At the vector of pairs (edge informations) of the node u, iterate through the weight of each connection between u and v
        if(dfs_num[neighbor_node] == UNVISITED)
            dfs_own(neighbor_node);
    }
}





int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    



}