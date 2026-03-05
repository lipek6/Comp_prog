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
        vector<int> h(n);
        vector<long long> presum(n+1); presum[0] = 0;


        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            presum[i+1] = presum[i] + a[i]; 
        }

        for(int i = 0; i < n; i++) cin >> h[i];



        int max_length = 0;
        int length = 0;
        
        int l = 0;
        int r = 0;
        
        for(r = 0; r < n; r++)
        {
            if(r > l && h[r-1] % h[r] != 0)
            {
                l = r;
            }

            while(presum[r+1] - presum[l] > k)
            {
                l++;       
            }

            max_length = max(max_length, r - l + 1);
        }

        cout << max_length << "\n";
    }

}