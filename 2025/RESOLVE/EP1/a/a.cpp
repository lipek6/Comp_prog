#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int shops; cin >> shops;

    vector<int> cost(shops); for(int i = 0; i < shops; i++) cin >> cost[i]; sort(cost.begin(), cost.end());

    int coins;
    int can_buy;
    int days; cin >> days;
    for(int i = 0; i < days; i++)
    {
        cin >> coins;
        can_buy = upper_bound(cost.begin(), cost.end(), coins) - cost.begin();
        cout << can_buy << "\n";
    }    
}