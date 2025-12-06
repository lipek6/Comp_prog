#include<bits/stdc++.h>
#define VISITED true
#define UNVISITED false
using namespace std;

vector<vector<int>> AL;
bool valid = false;
bool found = false;
vector<bool> a;
int m;

void dfs(int u, int &cats)
{    
    if(a[u] == true)
        cats++;
    else
        cats = 0;

    if(cats > m)
    {
        found = true;
        valid = false;
        return;
    }
    for(int i = 0; i < AL[u].size(); i++)
    {
        dfs(AL[u][i], cats);
    }
    if(cats <= m && found != true)
        valid = true;
    else 
        valid = false;

    return;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n >> m;
    AL.resize(n+1);
    a.assign(n+1, false);
    
    vector<bool> is_leaf(n+1, true);

    for(int i = 1; i <= n; i++)
    {
        int cat; cin >> cat;
        if(cat == 1) a[i] = true;
    }

    for(int i = 1; i < n; i++)
    {
        int x, y; cin >> x >> y;
        AL[y].push_back(x);
        is_leaf[x] = false;
    }

    int answer = 0;

    for(int i = 1; i <= n; i++)
    {
        if(is_leaf[i])
        {
            int cats = 0;
            dfs(i, cats);
            
            if(valid == true) answer++;
            found = false;
            valid = false;
        }
    } 
    cout << answer << "\n";
}