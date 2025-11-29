#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--)
    {
        int n; cin >> n;
        vector<pair<int,int>> events;
        for(int i = 0; i < n; i++)
        {
            int in, out; cin >> in >> out;
            events.push_back({in,   1});
            events.push_back({out, -1}); 
        }

        sort(events.begin(), events.end());

        int maximal = 0;
        int front   = 0;
        int back    = 0;

        for(int i = 0; i < events.size(); i += events[i].second+1)
        {
            back = front; 
            front = back + events[i].second;
            maximal++;            
        }
        cout << maximal << "\n";


    }



}