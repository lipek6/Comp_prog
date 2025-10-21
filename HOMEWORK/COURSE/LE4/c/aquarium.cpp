#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);


    int t;      // Amount of test cases
    int n;      // Number of collums of coral
    long long x;      // Max amout of water

    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        vector<int>a(n);
        
        for(int i = 0; i < n; i++) cin >> a[i];
        
        sort(a.begin(), a.end());
        long long l = 1;
        long long r = 2e9 + 7;
        
        int answer = 0;
        while(l <= r) 
        {
            long long mid = l + ((r - l)/2);
            
            long long count = 0;
            for(int j = 0; j < n; j++)
            {
                if (mid > a[j]) count += mid - a[j];
                if (count > x) break;
            }    

            if (count > x)
            {
                r = mid - 1;
            }
            else             
            {
                answer = mid; 
                l = mid + 1;
            }
        }
        cout << answer << endl;   
    }     
}
