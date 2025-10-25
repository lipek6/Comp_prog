#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--)
    {
        int y, x; cin >> y >> x;
        
        int value = 0;
        for(int i = y; i > 0; i--)
        {
            value += i + (i-1) - abs(x-i);
        }
        cout << value << "\n";
    }


}