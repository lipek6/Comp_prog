#include<bits/stdc++.h>
using namespace std;

// Species name for A is a suffix for a species name for BB
// Sufix, maybe I can treat that as a substring? I could read the names backwardly to speed up

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<string> specie(n);

    for(int i = 0; i < n; i++) cin >> specie[i];

    vector<char> str;
    int i = 1;
    int j = 1;
    char last1; 
    char last2;
    while(true)
    {
        if(i == n)
        {
            str.push_back(last1);
            i = 1;
            j++;
        }
        last1 = specie[i]  [specie[i].size() - j];
        last2 = specie[i-1][specie[i-1].size() - j];
        
        if(specie[i].size() < j || specie[i-1].size() < j)
        {
            reverse(str.begin(), str.end());
            for(int k = 0; k < str.size(); k++) cout << str[k];
            cout << "\n";
            return 0;
        }
        
        if(last1 != last2)
            break;
        i++;
    }
    cout << "Not found" << "\n";
}