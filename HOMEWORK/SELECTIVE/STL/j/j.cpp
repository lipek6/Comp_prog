#include<bits/stdc++.h>
using namespace std;

// The neighbors of each number is the most important thing
// Prefixal / Sufixal min max?
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> maxs(n);
        vector<int> mins(n);
        
        int max_val = 0;
        int min_val = INT_MAX;

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) 
        {
            max_val = max(max_val, a[n - i - 1]);
            min_val = min(min_val, a[i]);
            mins[i] = min_val; 
            maxs[n - i - 1] = max_val;      // backwards
        }
        
        cout << '1';            // The borders are always ok (I think) 
        for(int i = 1; i < n - 1; i++)
        {  
            if(a[i] > mins[i] && a[i] < maxs[i])
                cout << '0';
            else
                cout << '1';
            cout.flush();
        }
        cout << '1' << "\n";    // The borders are always ok (I think)
    }
}