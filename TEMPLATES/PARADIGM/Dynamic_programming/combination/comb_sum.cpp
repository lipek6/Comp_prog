#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string entry;
    getline(cin, entry);
    
    
    vector<int> arr;
    int target;

    int i = 14;
    while(entry[i] != ',')
    {
        arr.push_back(entry[i] - '0');
        i += 2;
    }
    i += 11;
    
    while(i  < entry.size())
    {
        target += entry[i] * ;
    }
}