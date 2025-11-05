#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    
    long long a;
    long long lowest_mana = 0;
    long long accumulator = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        
        accumulator += a;
        lowest_mana = min(accumulator, lowest_mana);
    }
    
    cout << abs(lowest_mana) << "\n";

}