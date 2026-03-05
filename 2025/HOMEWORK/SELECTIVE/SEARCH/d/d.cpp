#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;    // Amount of shops
    vector<int> x(n);   // Price on the ith shop
    for(int i = 0; i < n; i++) cin >> x[i];
    
    sort(x.begin(), x.end());
    
    int q; cin >> q;    // Amount of days
    int m;              // Amount of coins on each day
    for(int i = 0; i < q; i++)
    {
        cin >> m;
        if(m < x[0])
        {
            cout << "0" << "\n";
            continue;
        }

        auto it = upper_bound(x.begin(), x.end(), m);
        cout << (it - x.begin()) << "\n";
    }
}