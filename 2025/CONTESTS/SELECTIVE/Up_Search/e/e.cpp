#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long value = 1;
    long long result = 1;
    vector<long long> cool_cups;
    while(result < 1e16)
    {
        result = value * (value+1) * (value+2);
        cool_cups.push_back(result);
        value++;
    }

    int tc; cin >> tc;
    while(tc--)
    {
        long long l, r; cin >> l >> r;

        auto first_cup = lower_bound(cool_cups.begin(), cool_cups.end(), l);
        auto last_cup  = upper_bound(cool_cups.begin(), cool_cups.end(), r);

        cout << last_cup - first_cup  << "\n";
    }

}