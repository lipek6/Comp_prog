#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    // Shoot first, shoot first + 2....
        
    if(n == 1)
    {
        cout << "1" << "\n";
        cout << "1" << "\n";
        return 0;
    }

    if(n == 2)
    {
        cout << 2 << "\n";
        cout << "1" << " ";
        cout << "2" << "\n";
        
        return 0;
    }
    if(n % 2 == 0)
        cout << (n - n/2) + 1 << "\n";
    else
        cout << (n - n/2) << "\n";

    cout << "1" << " ";
    int i;
    for(i = 3; i < n+1; i += 2)
    {
        cout << i << " ";
    }
    if(n % 2 == 0)
        cout << n;
    cout << "\n";   
}