#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k; cin >> n >> k;
    long long x, a, b, c; cin >> x >> a >> b >> c;

    vector<long long> arr(n);
    arr[0] = x;
    for(int i = 1; i < n; i++) arr[i] = ((a * arr[i-1]) + b) % c;

    long long result;
    // First window
    long long window = arr[0];
    for(int i = 1; i < k; i++)
    {
        window = window xor arr[i]; 
    }
    
    result = window;

    for(int i = k; i < n; i++)
    {
        window = window xor arr[i-k]; // Remove element 
        window = window xor arr[i];   // Add element 
        result = result xor window;   // Xor the window
    }

    cout << result << "\n";
}