#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<long long> mult_guys;

    long long x = 1;
    long long result = 0;

    while(result <= 1e16)
    {
        result = x * (x + 1) * (x + 2);
        x++;
     
        mult_guys.push_back(result);    
    }


    int tc; cin >> tc;
    while(tc--)
    {
        long long L, R; cin >> L >> R;
        long long cups = upper_bound(mult_guys.begin(), mult_guys.end(), R) - lower_bound(mult_guys.begin(), mult_guys.end(), L);
        cout << cups << "\n";
    }
}