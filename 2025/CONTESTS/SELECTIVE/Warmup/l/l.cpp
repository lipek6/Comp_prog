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
        vector<int>a(n);     
        vector<int>neg;     
        vector<int>pos;     

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i] < 0) neg.push_back(a[i]);
            else pos.push_back(a[i]);
        }

        sort(neg.begin(), neg.end());
        sort(pos.begin(), pos.end());
        sort(a.begin(), a.end());
        
        for(int i = 0; i < n; i++)
        {
            int neg_diff = neg[0] - neg[neg.size()];

            if (neg_diff > a[n-1])
            
        }

    }
    
    
    int zeros = 0;

    while(n > 0)
    {
        zeros += n/5;
        n = n/5;
    }

    cout << zeros << "\n";
}