#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin >> n >> x;
    
    vector<long long> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());

    int wheels = 0;
    int i = 0;
    int j = n - 1;

    while(i <= j)
    {
        while(p[j] + p[i] > x)
        {
            wheels++;
            j--;
        }
        
        if(i > j) break;

        if(p[j] + p[i] <= x)
        {
            wheels++;
            i++;
            j--;
        }
    }
    cout << wheels << "\n";
}