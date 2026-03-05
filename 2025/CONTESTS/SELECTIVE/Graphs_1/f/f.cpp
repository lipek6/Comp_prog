#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s, t; cin >> s >> t;
    sort(t.begin(), t.end());

    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] - 65 >= 0 && s[i] - 65 <= 25) // Is uppercase
        {
            bool found = false;
            for(int j = 0; j < t.size(); j++)
            {
                if(t[j] == s[i-1])
                {
                    found = true;
                    break;
                }
            }
            if(!found)
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
}