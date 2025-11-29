#include<bits/stdc++.h>
#define INF 1e15
using namespace std;

vector<vector<long long>> fuel_AM;
vector<vector<long long>> AM;

long long full, L;
int n, m, queries;

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
        
        
        if(fuel_AM[source][destiny] == INF)
        {
            cout << "-1\n";
        }
        else
        {
            cout << fuel_AM[source][destiny] - 1 << "\n";
        }
    }
}

void get_input()
{
    cin >> n >> m >> L;

    fuel_AM.assign(n + 1, vector<long long>(n + 1, INF));
    AM.resize(n + 1, vector<long long>(n + 1, INF));

    for(int i = 1; i <= m; i++)
    {
        int a, b; long long c; cin >> a >> b >> c;

        if(c < AM[a][b])
        {
            AM[a][b] = c;
            AM[b][a] = c;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        AM[i][i] = 0;
        fuel_AM[i][i] = 0;
    }

    cin >> queries;
}

void floyd_warshall()
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(AM[i][k] == INF) continue;
            for(int j = 1; j <= n; j++)
            {
                if(AM[k][j] == INF) continue;

                long long detour_distance = AM[i][k] + AM[k][j];
                long long direct_distance = AM[i][j];
                
                AM[i][j] = min(detour_distance, direct_distance);
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j) continue;
            if(AM[i][j] <= L)
            {
                fuel_AM[i][j] = 1;
            }
        }
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if (fuel_AM[i][k] == INF) continue;
            for(int j = 1; j <= n; j++)
            {
                if (fuel_AM[k][j] == INF) continue;

                long long detour_fuel = fuel_AM[i][k] + fuel_AM[k][j];
                long long direct_fuel = fuel_AM[i][j];
                
                fuel_AM[i][j] = min(detour_fuel, direct_fuel);
            }
        }
    }
}