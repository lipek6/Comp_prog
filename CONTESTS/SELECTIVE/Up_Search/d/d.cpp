#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);   
    cin.tie(nullptr);

    int tc; cin >> tc;

    while(tc--)
    {
        int n, k; cin >> n >> k;

        vector<int> h(n);
        int top_height = 0;
        int current_height = 0;
        int water_heigth = 1;
        int teleport_time = 0;
        int next_height_idx = 0;
        bool possible = true;

        for(int i = 0; i < n; i++) cin >> h[i];

        current_height = h[k-1];

        sort(h.begin(), h.end());

        top_height = *(h.end() - 1);

        
        while(current_height != top_height)
        {
            next_height_idx = upper_bound(h.begin(), h.end(), current_height) - h.begin();      // Get the index of the next tower

            teleport_time = h[next_height_idx] - current_height; 

            water_heigth += teleport_time;

            if(water_heigth > current_height + 1)
            {
                possible = false;
                break;
            }
            
            current_height = h[next_height_idx];
        }
        if(possible) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}