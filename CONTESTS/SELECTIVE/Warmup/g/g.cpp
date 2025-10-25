#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t; cin >> t;
    string path;

    // Insert the double or half of the value
    while(t--)
    {
        cin >> n;
        vector<int>a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int init_size = a.size();
        int add = 0;
        for(int i = 1; i < a.size(); i++)
        {
            long long big  = max(a[i], a[i-1]);
            long long sml2 = min(a[i], a[i-1])*2;
            
            if(big < sml2)
            {
                continue;
            }
            else
            {
                a.insert(a.begin() + i, big/2 - 1);    
            }
        }
        int end_size = a.size();

        cout << init_size - end_size << "\n";
    }
}