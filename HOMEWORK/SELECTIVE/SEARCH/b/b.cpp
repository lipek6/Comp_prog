#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int start, end;
    vector<pair<int,int>> events;  // Input (time | action: in = 1, out = -1)
    
    for(int i = 0; i < n; i++)
    {
        cin >> start >> end;
        events.push_back({start, +1});
        events.push_back({end, -1});
    }
    
    sort(events.begin(), events.end());   // Sort by time
    
    // The "vector<int> intervals;" data is on the second element of each pair of the events vector

    vector<int> sweepline(events.size() + 1);          // Prefix Sum
    sweepline[0] = 0;

    int higher_count = 0;

    for(int i = 0; i < events.size(); i++)
    {
        sweepline[i+1] = sweepline[i] + events[i].second;
        higher_count = max(higher_count, sweepline[i+1]);
    }

    cout << higher_count << "\n";
}