#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--)
    {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        
        cin >> a[0];
        int a_xor = a[0];
        
        for(int i = 1; i < n; i++)
        {
            cin >> a[i];
            a_xor = a_xor xor a[i];
        }
        
        cin >> b[0];
        int b_xor = b[0];

        for(int i = 1; i < n; i++)
        {
            cin >> b[i];
            b_xor = b_xor xor b[i];
        }

        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0) // a
            {
                if(b_xor > a_xor)
                {
                    a_xor = (a_xor xor a[i]) xor b[i];
                    b_xor = (b_xor xor b[i]) xor a[i];
                    swap(a[i], b[i]);
                }
            }
        
            else
            {
                if(a_xor > b_xor)
                {
                    a_xor = (a_xor xor a[i]) xor b[i];
                    b_xor = (b_xor xor b[i]) xor a[i];
                    swap(a[i], b[i]);
                }
            }
        }

        if(a_xor == b_xor) 
            cout << "Tie\n";

        else if(a_xor > b_xor)
            cout << "Ajisai\n";
            
        else if(a_xor < b_xor)
            cout << "Mai\n";
    }
}