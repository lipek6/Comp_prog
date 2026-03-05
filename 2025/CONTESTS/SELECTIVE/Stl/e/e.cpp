#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    
    int t, d;
    cin >> t >> d;
    long long watching = t + d - 1;
    for(int i = 1; i < n; i++)
    {
        cin >> t >> d;
        
        if(t > watching)
        {
            watching = t + d;
        }
        else if(t <= watching)
        {
            watching += d;
        }
    }
    cout << watching << "\n";
}