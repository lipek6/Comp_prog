#include<bits/stdc++.h>
using namespace std;

// We need to find the median of windows of size 'k', that menas that we will sort the k elements and get the middle element
// That looks like something that would easily result into a TLE
// To optimize this, maybe I can find the median of the windows as a I get the input
// I can use the formula of the median, that is, the closest number to the average

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    vector<int> x(n);
    long long avg;
    
    long long window_sum = 0;
    long long window_median = LLONG_MAX;
    long long closest_diff  = LLONG_MAX;
    long long diff;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        window_sum += x[i];
        if(i >= k - 1)
        {
            avg = (window_sum / k);
            window_sum -= x[i + 1 - k];
            
            closest_diff = LLONG_MAX;
            for(int j = 0; j < k; j++)
            {
                diff = abs(avg - x[i - j]); 
                if(abs(closest_diff - avg) > diff) closest_diff = x[i - j];
                if(diff == 0) break;
            }
            cout << closest_diff << " ";
        }
    }
    cout << "\n";
}   // I think that this might be about O(n + n*k)?