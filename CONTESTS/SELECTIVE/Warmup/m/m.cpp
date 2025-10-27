#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        vector<int> b(k);

        long long cost = 0;
        for(int i = 0; i < n; i++) 
        {
            cin >> a[i];
            cost += a[i];
        }
        for(int i = 0; i < k; i++) cin >> b[i];
        sort(a.begin(), a.end(), greater());
        sort(b.begin(), b.end());
                

        int a_it = 0;
        for(int i = 0; i < k; i++)
        {
            int voucher_size = b[i];
            if(voucher_size + a_it > n) break;
            cost -= a[a_it + voucher_size - 1];
            a_it += voucher_size;
        }
        cout << cost << "\n";
    }
}