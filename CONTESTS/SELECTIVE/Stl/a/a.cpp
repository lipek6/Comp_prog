#include<bits/stdc++.h>
using namespace std;

// Greedy, go to closer while we still have steps
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t; cin >> n >> t;
    
    vector<pair<long long, long long>> xdist(n);  // Distance from 0 and Bonuses coordinate
    long long xi;
    for(int i = 0; i < n; i++)
    {
        cin >> xi;
        xdist[i].first  = abs(xi);
        xdist[i].second = xi;
    }
    sort(xdist.begin(), xdist.end());

    int curr_position = 0;
    long long bonuses = 0;
    for(int i = 0; i < n; i++)
    {
        t -= xdist[i].first;
        curr_position = xdist[i].second;
        
    }


}