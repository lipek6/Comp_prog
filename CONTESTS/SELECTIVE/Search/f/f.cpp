#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = s[i] + ('a' - 'A');
    }
    cout << s << "\n";

    for(int i = 0; i < s.length() - 1; i++)
    {
        string smod = s;
        if(s[i] == 's' && s[i+1] == 's')
        {
            string temp;
            copy(smod.begin() + i, smod.end(), temp.begin());
            smod[i] = 'B';
            for(int j = 0; j < s.length(); j++)
            {
                if(j != i+1) cout << smod[j];
            }
            cout << "\n";
        }
    }
}