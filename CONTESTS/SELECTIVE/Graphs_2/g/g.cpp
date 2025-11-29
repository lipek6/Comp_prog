#include<bits/stdc++.h>
using namespace std;

int test_radius(int m, vector<int>& x)
{
    int cows = 1;
    int pos  = x[0] + m;
    while(true)
    {
        


    }




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


    int l = 0;
    int r = n;

    int best_radius = 1e9;
    while(l <= r)
    {
        int m = l + ((r-l)/2);

        int curr_cows = test_radius(m, x);

        if(k > curr_cows)
        {
            l = m + 1;
        }
        else if(k < curr_cows)
        {
            r = m - 1;
            best_radius = min(best_radius, m);
        }
        else
        {
            best_radius = min(best_radius, m);
            break;
        }
    }

    cout << best_radius << "\n";
}