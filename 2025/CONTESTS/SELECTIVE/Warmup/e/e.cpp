#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<long long>arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long moves = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            moves += (arr[i] - arr[i + 1]);
            arr[i + 1] += arr[i] - arr[i + 1];
        }
    }
    cout << moves << "\n";
}