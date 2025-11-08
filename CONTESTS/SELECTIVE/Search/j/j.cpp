#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    int S, F; cin >> S >> F;

    vector<pair<int,int>> events;
    vector<int> timestamps;
    for(int i = 0; i < n; i++) 
    {
        int b, e;
        cin >> b >> e;

        events.push_back({b, 1});
        events.push_back({e+1, -1});
        timestamps.push_back(b);
        timestamps.push_back(e+1);
    }
    
    sort(events.begin(), events.end());
    sort(timestamps.begin(), timestamps.end());

    vector<int> presum(events.size() + 1); presum[0] = 0;

    for(int i = 0; i < events.size(); i++) 
    {   
        presum[i+1] = presum[i] + events[i].second;
    }


        for(int i = 1; i <= n; i++)
        {
            if (presum[i] < i)
            {
                for(int j = i; j <= n; j++)
                {
                    if(presum[j] > i) cout << events[i].first - events[j].first << " ";
                }
            }
            else
            {
                cout << "0" << " ";
            }
        }

    cout << "\n";


}