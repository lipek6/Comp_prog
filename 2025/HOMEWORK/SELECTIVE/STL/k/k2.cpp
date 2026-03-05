#include<bits/stdc++.h>
using namespace std;

// Species name for A is a suffix for a species name for BB
// Sufix, maybe I can treat that as a substring? I could read the names backwardly to speed up
// Now that I am thinking, it looks like the sufix string will always be the smallest string, so I can store that and just compare 
// the back of the other strings to it

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<string> specie(n);
    
    cin >> specie[0];
    string min_specie = specie[0];

    for(int i = 1; i < n; i++) 
    {
        cin >> specie[i];
        min_specie = specie[i].length() < min_specie.length() ? specie[i] : min_specie;
    }

    for(int i = 0; i < n; i++)
    {
        int first_char = specie[i].length() - min_specie.length();
        int k = 0;
        
        for(int j = first_char; j < specie[i].length(); j++)
        {
            if(specie[i][j] != min_specie[k])
            {
                    cout << "Not found" << "\n";
                    return 0;
            }
            k++;
        }
    }
    
    cout << min_specie << "\n";


}