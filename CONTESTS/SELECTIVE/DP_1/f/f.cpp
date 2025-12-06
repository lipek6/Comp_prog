#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<long long> dp(n, INF); dp[0] = a[0];                                                   

    for(int i = 0; i < n; i++)                                   
    {
        for(int j = i+k; j < n; j++)
        {
            dp[i+j] = max(dp[i] + dp[j], dp[i+j]);
        }                                           
    }
    cout << dp[n-1] << "\n";
}