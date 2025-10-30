#include<bits/stdc++.h>
using namespace std;

// We need to find the median of windows of size 'k', that menas that we will sort the k elements and get the middle element
// OK, I will use multiseeeet

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> x(n);
    multiset<int> window;    // Value and index
    
    for(int i = 0; i < n; i++) 
    {
        cin >> x[i];
    }
    
}