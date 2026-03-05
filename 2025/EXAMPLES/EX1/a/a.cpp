#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n; cin >> n;
    vector<int> x(n);
    
    if(n == 0)
    {
        cout << 0 << "\n"; 
        return 0;
    }

    int dist_num = 1;
    
    
    for(int i = 0; i < n; i++) cin >> x[i];                   
    sort(x.begin(), x.end());

    for(int i = 1; i < n; i++)
    {
        if(x[i-1] != x[i]) dist_num++;
    }
    cout << dist_num << "\n";
}