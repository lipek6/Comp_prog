#include<bits/stdc++.h>
using namespace std;


// When domino ii falls to the right, if the size of the domino placed immediately
// to the right of domino ii is at most 2Si2Si​, then that domino also falls to the right
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--)
    {
        int n; cin >> n;
        vector<int> domino(n);
        for(int i = 0; i < n; i++) cin >> domino[i];

        int first_domino = domino[0];
        int last_domino  = domino[n-1];
    
        sort(domino.begin(), domino.end());

        auto l = lower_bound(domino.begin(), domino.end(), first_domino) - domino.begin();
        auto r = lower_bound(domino.begin(), domino.end(), last_domino)  - domino.begin();

        int amount = 1;

        int current   = domino[l];
        int posterior = l+1;

        while(current * 2 > domino[posterior])
        {
            current = domino[posterior++];
        }

        cout << amount << "\n";
    }
}