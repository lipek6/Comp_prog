#include<bits/stdc++.h>
using namespace std;

// at least 2
// each pair of indices i and j the greatest common divisor (GCD) of aiai​ and ajaj​ is equal to 11

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    
    while(tc--)
    {
        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i < n; i++)
        {
            int GCD = gcd(a[i], a[i+1]);
            if(GCD != 1)
        }

        gcd
    }






}