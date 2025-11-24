#include<bits/stdc++.h>
#define UNVISITED 1e9       // Max for integer
using namespace std;

// Code for Breadth First Search (BFS) into an integer only Adjacent List (AL).
void bfs (int source_node, auto& AL, auto& dist);

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int amount_nodes, number_edges; cin >> amount_nodes >> number_edges;
    
    vector<vector<int>> AL(amount_nodes+1);
    vector<int> dist(amount_nodes+1, UNVISITED);

    for(int i = 0; i < number_edges; i++)
    {
        int node1, node2; cin >> node1 >> node2;
        AL[node1].push_back(node2);
        AL[node2].push_back(node1);
    }
    
    int source_node;  cin >> source_node;

    bfs(source_node, AL, dist);

    cout << "Doing a BFS from node " << source_node << "\n\n";

    for(int current_node = 1; current_node <= amount_nodes; current_node++)
    {
        for(int adjacent_node : AL[current_node])
        {
            cout << current_node << "<--->" << adjacent_node; 
        }
        cout << "\n";
    }

    cout << "The distances from the source node are: " << "\n";
    for(int i = 1; i <= amount_nodes; i++)
    {
        cout << "From source node to " << i << " The distance is " << dist[i] << "\n";
    }
}


void bfs (int source_node, auto& AL, auto& dist)
{
    queue<int> q; q.push(source_node);
    dist[source_node] = 0;

    while(!q.empty())
    {
        int current_node = q.front();
        q.pop();

        for(int adjacent_node : AL[current_node])
        {
            if(dist[adjacent_node] != UNVISITED) continue;

            dist[adjacent_node] = dist[current_node] + 1;
            q.push(adjacent_node);
        }
    }
}