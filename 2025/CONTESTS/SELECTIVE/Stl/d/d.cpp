#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> a(k);
    for(int i = 0; i < k; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    int weird = 0;
    for(int i = 1; i < k; i += 2)
    {
        if(i + 1 > a.size() - 1)
            weird += abs(a[i-1] - a[i]);
        else if(i - 1 < 0)
            weird += abs(a[i+1] - a[i]); 
        else
        {
            int ldiff = abs(a[i-1] - a[i]);
            int rdiff = abs(a[i+1] - a[i]);
            weird += min(ldiff, rdiff);
        }
    }
    cout << weird << "\n";
}