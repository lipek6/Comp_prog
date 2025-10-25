#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t; cin >> t;
    string path;

    while(t--)
    {
        cin >> n;
        cin >> path;

        int coins = 0;
        int i = 0;
        int stop = 0;

        for(int i = 0; i < n; i++)
        {
            if(stop == 2) break;
            if(path[i] == '@') coins++;
            if(path[i] == '*') 
            {
                stop++;
                continue;
            }
            if(stop == 1 && path[i] != '*') stop = 0;
        }
        cout << coins << "\n";
    }
}