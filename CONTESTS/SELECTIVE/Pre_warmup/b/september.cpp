#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    int count = 0;
    for(int i = 1; i <= 12; i++)
    {
        cin >> str;
        if(str.size() == i) count++;
    }
    cout << count << "\n";
}