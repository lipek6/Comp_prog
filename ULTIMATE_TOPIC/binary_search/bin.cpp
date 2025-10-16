#include<bits/stdc++.h>
using namespace std;

long long bin_search (const vector<long long>& arr, long long l, long long r, long long target)
{
    if(l > r)
    {
        return -1;
    }

    long long m = (l + ((r - l)/2));

    if(arr[m] == target)
    {
        return m;
    }
    else if(arr[m] < target) // Target is to the right
    {
        return bin_search(arr, m + 1, r, target);
    }
    else                     // Target is to the left
    {
        return bin_search(arr, l, m - 1, target);
    }
}


int main (void)
{
    long long n;          // Array size
    cin >> n;
    vector<long long> arr(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    long long target_value;
    cin >> target_value;
    
    long long target_idx = bin_search(arr, 0, n - 1, target_value);

    cout << "arr[" << target_idx << "] = " << target_value << "\n";
}