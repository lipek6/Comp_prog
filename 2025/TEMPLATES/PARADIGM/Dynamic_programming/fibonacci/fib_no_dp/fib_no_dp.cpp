#include<bits/stdc++.h>
using namespace std;

unsigned long long int fib (unsigned long long int n)
{
    if (n == 1) return 1;
    if (n == 0) return 0;
    
    return fib(n-1) + fib(n-2);
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long int n; cin >> n;

    unsigned long long int result = fib(n);

    cout << result << "\n";

}