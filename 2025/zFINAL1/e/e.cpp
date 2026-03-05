#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--)
    {
        int n, k; cin >> n >> k;
        string s; cin >> s; int sz = s.size();
        
        int operations = 0;
        for(int i = 0; i < sz; i++)
        {
            if(s[i] == 'B')
            {
                for(int j = i; j < i + k; j++)
                {
                    if(j >= sz) break;
                    s[j] = 'W';
                }
                operations++;
            }
        }

        cout << operations<< "\n";
    }
}