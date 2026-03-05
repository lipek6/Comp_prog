#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> t(n);

    for(int i = 0; i < n; i++) cin >> t[i];

    sort(t.begin(), t.end());

    for(int i = 0; i < q; i++)
    {
        int l, r; cin >> l >> r;

        cout << upper_bound(t.begin(), t.end(), r) - lower_bound(t.begin(), t.end(), l) << "\n";
    }


}