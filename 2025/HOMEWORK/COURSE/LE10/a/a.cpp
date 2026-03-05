#include<bits/stdc++.h>
using namespace std;


long long cross_product(pair<int,int> a, pair<int,int> b, pair<int,int> c)
{
    return 1LL * (b.first - a.first) * (c.second - a.second) - 1LL * (b.second - a.second) * (c.first - a.first);
}
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int,int>> pt(n);
    for(int i = 0; i < n; i++) cin >> pt[i].first >> pt[i].second;
    sort(pt.begin(), pt.end());
    
    vector<pair<int,int>> hull;

    for(int i = 0; i < n; i++)
    {
        while(hull.size() >= 2 && cross_product(hull[hull.size()-2], hull.back(), pt[i]) < 0)
            hull.pop_back();
        hull.push_back(pt[i]);
    }   
    int lower_hull_size = hull.size();

    for(int i = n - 2; i >= 0; i--)
    {
        while(hull.size() > lower_hull_size && cross_product(hull[hull.size()-2], hull.back(), pt[i]) < 0)
            hull.pop_back();
        hull.push_back(pt[i]);
    }
    
    hull.pop_back();

    cout << hull.size() << "\n";
    for(auto p : hull) cout << p.first << " " << p.second << "\n";

    return 0;
}
