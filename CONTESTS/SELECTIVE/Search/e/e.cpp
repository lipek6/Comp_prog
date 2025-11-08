#include<bits/stdc++.h>
using namespace std;

// Two pointers?
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc; cin >> tc;
    while(tc--)
    {
        long long cups = 0;
        long long L, R; cin >> L >> R;
        long long l = 0;
        long long r = R;

        long long min_m = 0;
        long long max_m = 0;
        long long m;
        while(l <= r)
        {
            m = l + (r-l) / 2;

            long long multi = m * (m+1) * (m+2);

            if(multi < L)
            {
                l = m + 1;
            }
            else if(multi > L)
            {
                r = m - 1;
            }
            else
            {
                min_m = m;
                break;
            }
        }
        min_m = m;

        l = 0;
        r = R;
        while(l <= r)
        {
            m = l + (r-l) / 2;

            long long multi = m * (m+1) * (m+2);

            if(multi < R)
            {
                l = m + 1;
            }
            else if(multi > R)
            {
                r = m - 1;
            }
            else
            {
                max_m = m;
                break;
            }
        }
        max_m = m;

        cups = (max_m - min_m);
        cout << cups << "\n";
    }
}