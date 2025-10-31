#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// This problems is a classic sliding window problem. We just need a prefix sum vector to find the sum at each of the windows and then,
// as the problem requires, we will make a XOR operation between the sums of each sliding window and output that.

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;               cin >> n >> k;              // Number of elements and size of the window
    int int_x, a, b, c;     cin >> int_x >> a >> b >> c;    

    vector<ll> psum(n+1);
    psum[0] = 0;
    psum[1] = int_x;

    vector<ll> x(n+1);       // We will not use index 0
    x[1] = int_x;
    for(int i = 2; i <= n; i++)
    {
        x[i] = ((a * x[i-1]) + b) % c;
        psum[i] = psum[i-1] + x[i];
    }
    
    
    ll windows_xor = 0;
    ll window_sum;
    
    for(int i = 1; i <= n + 1 - k; i++)
    {
        window_sum = psum[i + k - 1] - psum[i - 1];
        windows_xor = windows_xor ^ window_sum;
    }
    cout << windows_xor << "\n";
}