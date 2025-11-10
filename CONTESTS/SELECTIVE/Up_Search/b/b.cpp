#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vector<int> b(m, k);    
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int objects = 0;
    int i = n-1;
    int j = 0;

    while(i >= 0)
    {
        while(b[j] >= a[i] && i >= 0)
        {
            b[j] -= a[i];
            i--;
            objects++;
        }
        j++;
        
        if(j == m) break;
    }

    cout << objects << "\n";


}