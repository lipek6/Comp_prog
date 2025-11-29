#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s; 
    int s_size = s.size();
    
    map<char, bool> box;
    box['a'] = 0; box['b'] = 0; box['c'] = 0; box['d'] = 0; box['e'] = 0; box['f'] = 0; box['g'] = 0; box['h'] = 0;
    box['i'] = 0; box['j'] = 0; box['k'] = 0; box['l'] = 0; box['m'] = 0; box['n'] = 0; box['o'] = 0; box['p'] = 0; box['q'] = 0;
    box['r'] = 0; box['s'] = 0; box['t'] = 0; box['u'] = 0; box['v'] = 0; box['w'] = 0; box['x'] = 0; box['y'] = 0; box['z'] = 0;
    
    for(int i = 0; i < s_size; i++)
    {
        if(s[i] == ')')
        {
            int to_close = 1;
            for(int j = i - 1; j >= 0; j--)
            {
                if(s[j] == ')')
                {
                    to_close++;
                    continue;
                }
                if(s[j] == '(')
                {
                    to_close--;
                    if(to_close == 0)
                        break;
                    else
                        continue;
                }
                box[s[j]] = false;
            }
            if(to_close > 0)
            {
                cout << "No\n"; return 0;
            }
        }

        else if(s[i] == '(')
        {
            continue;
        }

        else
        {
            if(box[s[i]] == true)
            {
                cout << "No\n"; return 0;
            }
            else
            {
                box[s[i]] = true;
            }
        }
    }
    cout << "Yes\n";
}