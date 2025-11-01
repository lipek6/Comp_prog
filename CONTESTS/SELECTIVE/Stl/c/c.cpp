#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l = 1;
    int r = INT_MAX;
    int y = l + ((r - l)/2);

    string info;
    int queries = 0;
    while(true)
    {
        cout << "? " << y << endl;
        cin >> info;

        if(info == "YES")
        {
            l = y + 1;
            y = l + (r - l) / 2;
        }
        if(info == "NO")
        {
            r = y - 1;
            y = l + (r - l) / 2;
        }
        
        if(l >= r)
        {
            cout << "! " << y << endl;
            return 0;
        }
        
        queries++;
    }
    cout << "! " << y << endl;
}