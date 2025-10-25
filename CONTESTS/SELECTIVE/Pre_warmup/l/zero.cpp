#include<bits/stdc++.h>
using namespace std;

// At each multiple of 5, there is one more trailing zero
// Besides that, at each time that we have a 30, we have one more zero
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned long long n; cin >> n;
    
    int zeros = 0;

    while(n > 0)
    {
        zeros += n/5;
        n = n/5;
    }

    cout << zeros << "\n";
}