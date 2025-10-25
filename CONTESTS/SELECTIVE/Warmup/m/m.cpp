#include<bits/stdc++.h>
using namespace std;

// A non-degenerate triangle is when a < b + c
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int>a(n);     // products
        vector<int>b(k);     // vouchers

        for(int i = 0; i < n; i++) cin >> a[i]; // products
        for(int i = 0; i < k; i++) cin >> b[i]; // vouchers
        sort(a.begin(), a.end(), greater());
        sort(b.begin(), b.end());

        int cost = 0;
        int i = 0;
        while(i < n)
        {
            if(i >= k)
            {
                cost += a[i];
                i++;
            }
            else
            {
                if(b[i] == 1)
                {
                    i++;
                    continue;
                }
                int j = i;
                for(; j < i + b[i] - 1; j++)
                {
                    cost += a[j];
                }
                i += j - i;     
                i++;
            }
        }
        cout << cost <<"\n";
    }
}