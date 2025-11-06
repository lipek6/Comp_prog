#include<bits/stdc++.h>
using namespace std;

int n;

long long RecursiveDivision(vector<int>& p, long long sum1, long long sum2, int i)
{
    
    if(i == n) return (abs(sum1 - sum2));   
    long long diff1 = RecursiveDivision(p, sum1 + p[i], sum2, i + 1);    // Apple into group 1
    long long diff2 = RecursiveDivision(p, sum1, sum2 + p[i], i + 1);    // Apple into group 2
    
    return min(diff1, diff2);
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end(), greater());

    long long result = RecursiveDivision(p, 0, 0, 0);
    cout << result << "\n";
}

// 11
// 2 2 4 5 20 25 50 60 80 84 90