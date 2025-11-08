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
        multiset<int> h;
        int init_h;
        int max_tower = 0;
        for(int i = 0; i < n; i++)
        {
            int hi; cin >> hi;
            h.insert(hi);
            if(i == k-1) init_h = hi;
            max_tower = max(max_tower, hi);
        }

        int lvl = 1;
        while(lvl <= init_h)
        {
            int next_tower = *(h.upper_bound(init_h));
            lvl += (next_tower - init_h);

            if(lvl <= init_h  + 1)
            {
                init_h = next_tower;
            }
            if(init_h == max_tower)
            {
                break;
            }
        }
        if(init_h == max_tower)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}