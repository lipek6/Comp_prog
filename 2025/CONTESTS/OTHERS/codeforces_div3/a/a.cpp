#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    
    while(tc--)
    {
        int n; cin >> n;

        int max_cows = n / 4;
        int max_chickes = n / 2;

        if(n % 2 != 0 && n % 4 != 0)
        {
            cout << "0\n";
            continue;
        }

        long long total = 0;

        int chickens = max_chickes;
        for(int cows = 0; cows <= max_cows; cows++)
        {
            for(int chickens = max_chickes; chickens >= 0; chickens--)
            {
                long long result = (4 * cows) + (2 * chickens);
                if(result < n) break;
                if(result == n) total++;

            }



        }
        cout << total << "\n";

    }

}