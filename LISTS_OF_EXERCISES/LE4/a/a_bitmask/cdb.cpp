#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;        // Size of the tape in minutes
    int t_count;  // Amount of tracks

    while(cin >> n)
    {
        cin >> t_count;

        vector<int> t(t_count);
        int max_mask = 0;
        int max_sum  = 0;

        for (int i = 0; i < t_count; i++) cin >> t[i];


        for (int i = 0; i < (1 << t_count); i++)
        {
            int sum = 0;
            for (int j = 0; j < t_count; j++) if((i >> j) & 1) sum += t[j];

            if((n - sum) < (n - max_sum) && sum <= n)
            {
                max_sum  = sum;
                max_mask = i;
            }

        }

        for (int i = 0; i < t_count; i++) if ((max_mask >> i) & 1) cout << t[i] << " ";
        cout << "sum:" << max_sum << "\n";
    }
}