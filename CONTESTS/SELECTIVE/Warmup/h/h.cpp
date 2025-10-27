#include<bits/stdc++.h>
using namespace std;

// All the time you see a signal swap, count + 1
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int ai;
        vector<int> a;

        long long sum = 0; 
        for(int i = 0; i < n; i++)
        {
            cin >> ai;
            if(ai != 0)
            {
                a.push_back(ai);
                sum += abs(ai);
            }
        }

        int i = 0;
        int actions = 0; 

        while(i < a.size())
        {
            while(a[i] < 0 && i < a.size())
            {
                i++;
            }
            if(i > 0)
            {
                actions++;
            }
            while(a[i] > 0  && i < a.size())
            {
                i++;
            }
        }
    
        cout << sum << " " << actions << "\n";
    }
}