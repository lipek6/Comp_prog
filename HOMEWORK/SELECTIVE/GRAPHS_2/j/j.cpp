#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> AL;
vector<tuple<int,int,int>> EL;
vector<int> representative;
vector<int> set_size;

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
    
    return;
}



// Something like a Minimum spanning tree (not exactly, but my idea is to use DSU with the capability to remove elements of sets)
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int islands, bridges; cin >> islands >>  bridges;
    
    representative.resize(islands + 1); iota(representative.begin(), representative.end(), 0);
    set_size.assign(islands + 1, 1);
    AL.resize(islands + 1);

    for(int i = 1; i <= bridges; i++)
    {
        int island1, island2; cin >> island1 >> island2;

        AL[island1].push_back({i, island2});
        AL[island2].push_back({i, island1});
        EL.push_back({i, island1, island2});

        join(island1, island2);
    }

    long long inconvenience = 0;
    for(auto& [i, island1, island2]: EL)
    {
        for(int j = 0; j < representative.size(); j++)
        {
            if (j >= representative[j]) inconvenience++;
        }
        cout << inconvenience << "\n";
    }
}