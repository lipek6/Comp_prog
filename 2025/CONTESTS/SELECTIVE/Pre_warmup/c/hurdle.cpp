#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str; cin >> str;

    int buffer = 0;
    for (int i = 1; i <= str.size(); i++)
    {
        if (str[i] == '|')
        {
            cout << buffer << " ";
            buffer = 0;
        }
        else buffer++;
    }
}