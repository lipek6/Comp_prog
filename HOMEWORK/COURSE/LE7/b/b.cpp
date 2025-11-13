#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> AL;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    AL.resize(n+1);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int cost; cin >> cost;
            AL[i].push_back({cost, j});
        }
    }
}