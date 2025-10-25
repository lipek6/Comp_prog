#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n, k; cin >> n >> k;
    
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    long long amount = 0;
    long long sum = 0;
    int l = 0;
    for(int i = 0; i < n; i++) 
    {
        sum += a[i];
        while(sum >= k)
        {
            amount += n - i;
            sum -= a[l];        //WHYYYY
            l++;
        }
    }
    cout << amount << "\n";
}