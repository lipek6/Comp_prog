#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, d; cin >> n >> k >> d;

    vector<int> p(k);
    vector<vector<int>> AL(n+1);

    for(int i = 0; i < k; i++) cin >> p[i];
    for(int i = 0; i < n - 1; i++)
    {
        int city1, city2;
        cin >> city1 >> city2;
        AL[city1].push_back(city2);
        AL[city2].push_back(city1);
    }











}