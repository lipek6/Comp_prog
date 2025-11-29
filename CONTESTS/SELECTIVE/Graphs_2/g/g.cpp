#include<bits/stdc++.h>
using namespace std;

int test_radius(int m, vector<int>& dist)
{
    auto up = upper_bound(dist.begin(), dist.end(), m);
    auto lw = lower_bound(dist.begin(), dist.end(), m);
    return up - lw;
}

// Dp on the answer???
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    
    int n, k; cin >> n >> k;
    
    vector<int> dist;
    vector<int> x(n);

    for(int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    for(int i = 0; i < n-1; i++)
    {
        dist.push_back(x[i+1] - x[i]);
    }
    sort(dist.begin(), dist.end(), greater());


    int l = 0;
    int r = n;

    int best_radius = 1e9;
    while(l <= r)
    {
        int m = l + ((r-l)/2);

        int curr_radius = test_radius(m, dist);

        if(k > curr_radius)
        {
            l = m + 1;
        }
        else if(k < curr_radius)
        {
            r = m - 1;
            best_radius = min(best_radius, curr_radius);
        }
        else
        {
            best_radius = min(best_radius, curr_radius);
            break;
        }
    }
    cout << best_radius << "\n";

}