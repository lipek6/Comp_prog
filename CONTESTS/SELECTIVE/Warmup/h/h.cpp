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
        long long answ = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            answ += abs(a[i]);
        }

        long long ops  = 0;
        int l = 0;
        int r = n - 1;

        int i = 0;
        int pos = 0;
        int neg = 0;

        while(true)
        {
            if(a[i] >= 0)
            {
                pos++;
            }            
            else neg++;

        }




        
    }
}