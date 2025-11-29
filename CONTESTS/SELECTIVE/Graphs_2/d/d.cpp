#include<bits/stdc++.h>
#define WHITE true
#define BLACK false
using namespace std;

vector<int> representatives;
vector<int> black_set;
vector<int> white_set;
vector<int> set_size;
vector<bool> color;
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

    // 2 is always bigger
    if(set_size[node1] > set_size[node2]) swap(node1, node2);

    set_size[node2] += set_size[node1];
    representatives[node1] = node2;

    white_set[node2] += white_set[node1];
    black_set[node2] += black_set[node1];
    sets_amount--;
    return;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    representatives.resize(n + 1); iota(representatives.begin(), representatives.end(), 0);
    set_size.assign(n + 1, 1); set_size[0] = 0;     // Node zero is sad
    color.assign(n + 1, WHITE);
    black_set.assign(n+1, 0);
    white_set.assign(n+1, 1);
    sets_amount = n;


    for(int i = 0; i < q; i++)
    {
        int qtype; cin >> qtype;

        if(qtype == 1)
        {
            int u, v; cin >> u >> v;
            join(u, v);
        }
    
        else if (qtype == 2)
        {
            int v; cin >> v;
            if(color[v] == WHITE)
            {
                color[v] = BLACK;
                v = find(v);
                white_set[v]--;
                black_set[v]++;
            }
            else
            {
                color[v] = WHITE;
                v = find(v);
                black_set[v]--;
                white_set[v]++;
            }
        }
        else
        {
            int u; cin >> u;
            if(black_set[find(u)] > 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}