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
        vector<int> a(n);

        int swaps = 0;
        int sum   = 0; 
        bool curr_signal = 0;
        bool last_signal = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += abs(a[i]);
            
            if(a[i] > 0)
                curr_signal = 1;
            else if(a[i] < 0)
                curr_signal = 0; 
            
            if(curr_signal != last_signal && i > 0)
                swaps++;

            last_signal = curr_signal;
        }        
        if (curr_signal == 0 && swaps == 0) swaps++;
        cout << sum << " " << swaps << "\n";
    }
}