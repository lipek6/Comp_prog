#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n, t; cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        
        int additions = 0;
        for(int i = 0; i < a.size() - 1; i++)
        {
            int maximal = max(a[i], a[i + 1]);
            int minimal = min(a[i], a[i + 1]);

            bool is_dense = maximal <= 2 * minimal;
  
            // Optimizing run time by not inserting things on the vector and just counting how many more numbers we will need on that position
            while(!is_dense)
            {
                minimal = minimal * 2;
                is_dense = maximal <= 2 * minimal;
                additions++;
            }
        }
        cout << additions << "\n";
    }
}