#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--)
    {
        int n; cin >> n;

        vector<int> a(n);
        vector<int> diff(n, INF);
        
        cin >> a[0];
        
        long long empty_spaces = 0;
        long long sum_diff = 0;
        long long neg = 0;
        long long pos = 0;
        for(int i = 1; i < n; i++)
        {
            cin >> a[i];
            
            if(a[i] == -1) 
            {
                empty_spaces++;
                continue;
            }
            if(a[i-1] == -1) continue;

            diff[i] = a[i] - a[i-1];
            
            if(diff[i] > 0) 
                pos += diff[i];
            else
                neg += diff[i]; 
        }

        long long the_difference = abs(abs(pos) - abs(neg));

        if(empty_spaces != 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(diff[i] == INF && a[i] == -1) 
                {
                    a[i] = the_difference / empty_spaces;
                }
            }
        } 

        for(int i = 0; i < (n-1); i++) sum_diff += a[i+1] - a[i];
        
        cout << abs(sum_diff) << "\n";
        
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        
        cout << "\n";
    }
}