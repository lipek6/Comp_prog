#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    string r;
    int sz = s.size();

    for(int i = 0; i < sz; i++)
    {
        r.push_back(s[i]);
        if(r.size() >= 3 && r[r.size() - 1] == 'C' && r[r.size() - 2] == 'B' && r[r.size() - 3] == 'A')
        {
            r.pop_back();
            r.pop_back();
            r.pop_back();
        }
    }
    cout << r << "\n";
}