#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++) cin >> num[i];
    sort(num.begin(), num.end());

    int dists = 0;
    for(int i = 1; i < n; i++)
    {
        if(num[i] != num[i-1]) dists++;
    }

    cout << dists+1 << "\n";            // Plus 1 because we didn't count the first number
}