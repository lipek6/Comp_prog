#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> q;
    
    set<string> dict;

    while(q--)
    {
        int cmd; cin >> cmd;
        if(cmd == 1)
        {
            string word; cin >> word;
            dict.insert(word);
        }
        else if(cmd == 2)
        {
            int x; cin >> x;
            dict.erase();
        }
        else
        {
            while(dict[])
        }
    }

}