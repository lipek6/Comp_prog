#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k; cin >> k;

    vector<vector<int>> sequence(k);
    vector<vector<int>> psum(k);

    for(int i = 0; i < k; i++)
    {
        int n; cin >> n;
        psum[i].push_back(0);
        for(int j = 0; j < n; j++)
        {
            int val; cin >> val;
            sequence[i].push_back(val);
            psum[i].push_back(val + psum[i][j]);
        }
    }
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            if(j == i) continue;

            int diff = abs(psum[j][psum[j].size() - 1] - psum[i][psum[i].size() - 1]); // Total sum diff
            
        }
    }











}
