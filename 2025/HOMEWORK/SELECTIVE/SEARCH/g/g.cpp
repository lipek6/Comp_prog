#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<pair<int,int>> events;
    for(int i = 0; i < n; i++)
    {
        int in, out;
        cin >> in >> out;
        events.push_back({in, 1});
        events.push_back({out+1, -1}); // We can't start to watch another thing at moment 'out' exactly
    }
    sort(events.begin(), events.end());
    

    int front = 0;
    int back  = 0;

    for(int i = 0; i < events.size(); i++)
    {
        back = front; 
        front = back + events[i].second;
        if(front >= 3)
        {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
}