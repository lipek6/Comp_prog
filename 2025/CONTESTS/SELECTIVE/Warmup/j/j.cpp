#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end(), greater());
    
        int i = 0;
        int count = 0;

        while(a[i] > a[n-1] && i < n)
        {
            count++;
            i++;
        }
        cout << count << "\n";
    }
}
