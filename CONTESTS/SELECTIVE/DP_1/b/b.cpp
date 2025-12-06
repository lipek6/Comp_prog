#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int a, b; cin >> a >> b;
        int diff = abs(a - b);
        int extra = 0;
        if(diff % 10 != 0)
            extra = 1;
        cout << (diff / 10)+ extra << "\n";
    }
}