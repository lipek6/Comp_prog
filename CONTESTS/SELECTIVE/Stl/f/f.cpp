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
        vector<int> odds;
        vector<int> evens;
        int ai;
        for(int i = 0; i < n; i++) cin >> a[i];
        
        int balls = 0;
        int i = 0;
        while(true)
        {
            int x = -1;
            int issues = 0;
            while(issues < k)
            {
                if(a[i] % 2 == x)
                    issues++;
                else 
                    issues = 0;
                x = a[i] % 2;
                balls += a[i++];
            }

        }
        cout << balls << endl;  
    }
}