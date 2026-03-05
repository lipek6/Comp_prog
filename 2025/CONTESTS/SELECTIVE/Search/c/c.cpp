#include<bits/stdc++.h>
using namespace std;

// Sweep line, the cards have intervals
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<pair<int,int>> events;
    for(int i = 0; i < m; i++) 
    {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r+1, -1});    // Probably + 1, r is inclusive
    }
    
    sort(events.begin(), events.end());

    vector<long long> presum(events.size() + 1); presum[0] = 0;
    
    long long valid_cards = 0;
    int j = 0;
    for(int i = 0; i < events.size(); i++) 
    {
        if(j == n) break;

        presum[i+1] = presum[i] + events[i].second;

        if(presum[i+1] == m)
        {
            for (int k = 0; k < events[i+1].first - events[i].first; k++)
            {
                if(j < n)
                {
                    valid_cards++;
                    j++;
                }
            }
        }
    }

    cout << valid_cards << "\n";
}