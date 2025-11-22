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

        





    }


}