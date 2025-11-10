#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    
    vector<pair<int,int>> events;
    for(int i = 0; i < M; i++)
    {
        int l, r; cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r+1, -1});
    }
    sort(events.begin(), events.end());

    int cards = 0;
    int j = 0;
    vector<long long> presum(events.size() + 1); presum[0] = 0;
    for(int i = 0; i < events.size(); i++)
    {
        if(j == N) break;

        presum[i+1] = presum[i] + events[i].second;
        
        if(presum[i+1] == M) 
            cards += events[i+1].first - events[i].first;
    }

    if(cards > N) cards = N;
    cout << cards << "\n";
}
