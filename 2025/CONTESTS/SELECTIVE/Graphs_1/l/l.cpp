#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<pair<int,int>, pair<int,int>>> EL;

    int min_x = 1e9;
    int min_y = 1e9;
    int max_x =  -1;
    int max_y =  -1;

    vector<pair<int,int>> coordinates(n);
    for(int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        coordinates[i] = {x, y};

        min_x = min(min_x, x);
        min_y = min(min_y, y);
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }

    
    //for(int i = 0; i < n-1; i++)
    //{        
    //    EL.push_back({coordinates[i], coordinates[i+1]});
    //}
//
    //for(int i = 0; i < n-1; i++)
    //{
    //    auto& [pt1, pt2] = EL[i];
//
    //    if(pt1.first )
    //}

    cout << 4 << "\n";
    cout << max_x << " " << min_y << "\n";
    cout << max_x << " " << max_y << "\n";
    cout << min_x << " " << max_y << "\n";
    cout << min_x << " " << min_y << "\n";
}