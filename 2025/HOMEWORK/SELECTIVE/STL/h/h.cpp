#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// We want to buy the maximum amount of pairs of shoes inside our budget of 'k' bells
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; ll k;
    cin >> n >> k;
    
    vector<int> l(n);
    vector<int> r(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++) cin >> r[i];
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    ll pair_cost;
    ll pairs = 0;
    ll spent = 0;
    for(int i = 0; i < n; i++)
    {
        pair_cost = l[i] + r[i];
        if(spent + pair_cost > k) break;
        spent += pair_cost;
        pairs++;
    }
    cout << pairs << "\n";
}