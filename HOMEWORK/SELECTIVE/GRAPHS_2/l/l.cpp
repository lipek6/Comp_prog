#include<bits/stdc++.h>
#define INF 1e18
using namespace std;

vector<vector<long long>> parent;
vector<vector<long long>> AM;

long long full, L;
int n, m, queries;

int get_path(long long source, long long destiny);
void floyd_warshall();
void get_input();

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    get_input();
    floyd_warshall();

    while(queries--)
    {
        int source, destiny; cin >> source >> destiny;
        
        int recharges = get_path(source, destiny);
        if(recharges < 0)
        {
            cout << "-1\n";
        }
        else
        {
            cout << recharges << "\n";
        }
    }
}

void get_input()
{
    cin >> n >> m >> L;
    full = L;

    parent.resize(n + 1, vector<long long>(n + 1, INF));
    AM.resize(n + 1, vector<long long>(n + 1, INF));

    for(int i = 1; i <= m; i++)
    {
        int a, b; long long c; cin >> a >> b >> c;

        AM[a][b] = c;
        AM[b][a] = c;
    }

    for(int i = 1; i <= n; i++) AM[i][i] = 0;

    cin >> queries;
}

void floyd_warshall()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            parent[i][j] = i;
        }
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                long long detour_distance = AM[i][k] + AM[k][j];
                long long direct_distance = AM[i][j];
                if(detour_distance < direct_distance)
                {
                    AM[i][j] = detour_distance;
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
}

int get_path(long long source, long long destiny)
{
    if(AM[source][destiny] == INF) return -1;
    
    L = full;
    int recharges = 0;
    
    vector<pair<int,int>> path;
    while(source != destiny)
    {
        path.push_back({destiny, parent[source][destiny]});
        destiny = parent[source][destiny];
    }
    path.push_back({source, destiny});
    reverse(path.begin(), path.end());

    for(int i = 0; i < path.size(); i++)
    {
        long long spent_litters = AM[path[i].first] - AM[path[i].second];

        if(L - spent_litters < 0)
        {
            L = full;
            recharges++;
        }

        L -= spent_litters;

        if(L < 0)
        {
            return -1;
        }
    }
    return recharges;
}