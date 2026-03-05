#include<bits/stdc++.h>
using namespace std;

vector<int> representatives;
vector<int> set_size;
int sets_amount;

int find(int node)
{
    if(representatives[node] == node)
        return node;

    return representatives[node] = find(representatives[node]);
}

void join (int node1, int node2)
{
    node1 = find(representatives[node1]);
    node2 = find(representatives[node2]);

    if(node1 == node2) return;

    if(set_size[node1] > set_size[node2]) swap(node1, node2);

    set_size[node1] += set_size[node2];
    representatives[node2] = node1;
    sets_amount--;
    return;
}


// We will probably do the reverse, we will join the nodes indicated by the edges in the queries in reverse order and then count the sets amount
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes, edges; cin >> nodes >> edges;

    vector<pair<int, int>> EL(edges+1);  // Strange Edge list, so we can get the edges by their index

    representatives.resize(nodes + 1); iota(representatives.begin(), representatives.end(), 0);
    set_size.assign(nodes + 1, 1); set_size[0] = 0;     // Node zero is sad
    sets_amount = nodes;

    for(int i = 1; i <= edges; i++)
    {
        int node1, node2; cin >> node1 >> node2;
        EL[i] = {node1, node2};
    }


    // Getting the queries in reverse order, because we will restore edges instead of deleting then, and marking the edges that will always be there
    int queries; cin >> queries;
    vector<int>  restore_edge(queries);
    vector<bool> initial_edges(edges + 1, true); initial_edges[0] = false;
    for(int i = queries - 1; i >= 0; i--)
    {
        cin >> restore_edge[i];
        initial_edges[restore_edge[i]] = false;
    }


    // Computing the last moment where we have removed all edges that were on the queries
    vector<int> printer_buffer(queries);
    for(int i = 1; i <= edges; i++)
    {
        if(initial_edges[i])
        {
            int node1 = EL[i].first;
            int node2 = EL[i].second;
            join(node1, node2);
        }
    }
    printer_buffer[queries - 1] = sets_amount;          // Putting the last querie on the printer buffer

    // Computing all other queries
    for(int i = 0; i < queries - 1; i++)                    
    {
        int node1 = EL[restore_edge[i]].first;
        int node2 = EL[restore_edge[i]].second;

        join(node1, node2);
        printer_buffer[(queries - 2) - i] = sets_amount;
    }
    
    for(int to_print : printer_buffer) cout << to_print << " ";
    cout << "\n";
}