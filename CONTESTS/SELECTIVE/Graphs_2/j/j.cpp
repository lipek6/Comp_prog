#include<bits/stdc++.h>
using namespace std;
int rmvs = 0;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> AL(n+1);

    for(int i = 1; i <= n; i++)
    {
        int u, v; cin >> u >> v;

        AL[u].push_back(v);
        AL[v].push_back(u);
    }


    for(int i = 1; i <= n; i++)
    {
        for(int adj : AL[1])
        {
            if(AL[adj].size() > 1)
            {

            }



        }
    }
}

void rec (int node)
{
   if(AL[node].size() == 1) 
   {
        rmvs++;
        return;
   }
   else
   {
        for(int adj : AL[node])
        {
            if(!visited[adj])
            {
                return rec(adj);
            }

        }
   }



}