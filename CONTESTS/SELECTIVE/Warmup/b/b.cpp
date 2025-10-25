#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b; cin >> t;

    while(t--)
    {
        cin >> a >> b;
        int moves = 0;
        while (a != b)
        {
            int diff = a - b;
            if (diff > 0)               //Subtract
            {
                if (diff % 2 == 0) a = a - abs(diff);
                else a = a - (abs(diff) + 1);
            }
            else if (diff < 0)
            {
                if (diff % 2 != 0) a = a + abs(diff);
                else a = a + (abs(diff) - 1);
            }
            else break;
            moves++;
        }
        cout << moves << "\n";
    }
}