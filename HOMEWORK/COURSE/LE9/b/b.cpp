#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    string t; cin >> t;
    
    int tsize = t.size();
    int ssize = s.size();

    if(tsize > ssize)
    {
        cout << 0 << "\n";
        return 0;
    }
    
    vector<int> presum(tsize, 0);

    int occurrences = 0;
    int j = 0;

    for(int i = 1; i < tsize; i++)
    {
        while(j > 0 && t[i] != t[j])
            j = presum[j-1];
        
        if(t[i] == t[j])
            j++;

        presum[i] = j;
    }

    j = 0;
    for (int i = 0; i < ssize; i++)
    {
        while (j > 0 && s[i] != t[j]) 
            j = presum[j - 1];
        
        
        if (s[i] == t[j])
            j++;

        if (j == tsize)
        {
            occurrences++;
            j = presum[j - 1]; 
        }
    }
    cout << occurrences << "\n";
}