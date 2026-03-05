#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c; cin >> a >> b >> c;

    int divisors = 0;
    for(int i = a; i <= b; i++)
    {
        if(c % i == 0) divisors++;
    }

    cout << divisors << "\n";
}