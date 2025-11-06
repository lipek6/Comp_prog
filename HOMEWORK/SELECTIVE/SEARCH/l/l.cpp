#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    
    vector<pair<int,int>> events; // Like in all problems like this one
    vector<int> timestamps;

    for(int i = 0; i < n; i++)
    {
        int li, ri; cin >> li >> ri;

        events.push_back({li,  1});
        events.push_back({ri + 1, -1});
        timestamps.push_back(li);
        timestamps.push_back(ri+1);
    }
    sort(events.begin(), events.end());
    sort(timestamps.begin(), timestamps.end());

    vector<int> presum(events.size()+1); presum[0] = 0;
    for(int i = 0; i < events.size(); i++)
    {
        presum[i+1] = presum[i] + events[i].second;
    }

    int accepting_bears = 0;
    for(int i = 0; i < q; i++)
    {
        int t; cin >> t;

        auto upper_temp = upper_bound(timestamps.begin(), timestamps.end(), t);
        
        accepting_bears = presum[upper_temp - timestamps.begin()];
        cout << accepting_bears << "\n";
    }
}