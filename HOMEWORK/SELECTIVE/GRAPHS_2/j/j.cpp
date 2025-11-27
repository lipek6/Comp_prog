#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> EL;
vector<int> representative;
vector<int> set_size;
long long sets_amount;

// Find with path compression
int find(int node)
{
    if (node == representative[node])
        return node;
    
    return representative[node] = find(representative[node]);
}

// Join with smaller to large
void join(int node1, int node2)
{
    node1 = find(node1);
    node2 = find(node2);

    if(node1 == node2)
        return;

    if(set_size[node1] > set_size[node2])
        swap(node1, node2);
    
    representative[node1] = node2;
    set_size[node2] += set_size[node1];
    sets_amount--;
    
    return;
}



// Something like a Minimum spanning tree (not exactly, but my idea is to use DSU with the capability to remove elements of sets)
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long islands, bridges; cin >> islands >>  bridges;
    sets_amount = islands;
    
    representative.resize(islands + 1); iota(representative.begin(), representative.end(), 0);
    set_size.assign(islands + 1, 1);


    for(int i = 1; i <= bridges; i++)
    {
        int island1, island2; cin >> island1 >> island2;
        EL.push_back({i, island1, island2});
    }
        
    vector<long long> printer;

    long long inconvenience = (islands * (islands - 1)) / 2;
    printer.push_back(inconvenience);        
    
    for(int i = bridges - 1; i >= 1; i--)
    {
        auto& [j, island1, island2] = EL[i];

        int set_root1 = find(island1);
        int set_root2 = find(island2);

        if(set_root1 != set_root2)
        {
            inconvenience -= set_size[set_root1] * set_size[set_root2];
        }

        printer.push_back(inconvenience);        
        join(set_root1, set_root2);
    }
    
    reverse(printer.begin(), printer.end());
    for(int i = 0; i < printer.size(); i++) cout << printer[i] << "\n";
}