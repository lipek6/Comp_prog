#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // In an operation you can take any kk consecutive cells and make them all white.

    int t, n, k;        // Test cases, Length and integert used in the operation
    string s;

    cin >> t;
    while(t--)
    {
        int ops =  0;
        cin >> n >> k;
        cin >> s;
        // WBWWWB

        for(int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                for (int j = i; j - i < k; j++)
                {
                    if(j < n) s[j] = 'W';
                }
                ops++;
            }
        }
        cout << ops << "\n";
    }
}