#include<bits/stdc++.h>
using namespace std;

// A non-degenerate triangle is when a < b + c
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;
    vector<long long> a(n);
    
    for(long long i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());


    for(long long i = 2; i < n; i++)
    {
        if(a[i] < a[i - 2] + a[i - 1])
        {
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
}