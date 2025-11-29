#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int movies, members; cin >> movies >> members;
    
    vector<pair<int,int>> events;
    
    // Start + 1, ending -1
    for(int i = 0; i < movies; i++)
    {
        int start, ending; cin >> start >> ending;

        events.push_back({start, 1});    
        events.push_back({ending, -1});    
    }

    sort(events.begin(), events.end());

    vector<long long> presum(events.size() + 1); presum[0] = 0;

    int front = 0;
    int back  = 0;

    for(int i = 0; i < events.size(); i++)
    {
        presum[i+1] = presum[i] + events[i].second;
        
        if(presum[i] )
    }



}