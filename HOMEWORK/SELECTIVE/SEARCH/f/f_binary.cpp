#include<bits/stdc++.h>
using namespace std;

// Check if the middle pass through the things
long long pass (long long m, vector<int>& a)
{
    int i = 0;
    while(m >= 0)
    {
        if(i == a.size())
            break;
        m += a[i];
        i++;
    }
    return m;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    long long l = 0;
    long long r = 1e15;
    long long m;
    long long answer = 0;

    // Binary search on the answer
    while(l <= r)
    {
        m = l + (r - l) / 2;

        long long result = pass(m, a);

        if(result < 0)
        {
            l = m + 1;
        }
        if(result >= 0)
        {
            r = m - 1;
            answer = m;
        }
    }
    cout << answer << "\n";
}