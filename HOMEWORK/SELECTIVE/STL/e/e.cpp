#include<bits/stdc++.h>
using namespace std;

// We must find a substring 'u' inside the string 't', for that, we will use the size of 'u' and everywhere we find a '?' in 't'

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string t, u; cin >> t >> u;

    int tsize = t.length();
    int usize = u.length();

    int substring_size = 0;
    int j = 0;
    for(int i = 0; i < tsize; i++)
    {
        
        while((t[i] == u[j] || t[i] == '?') && (i < tsize && j < usize))                  // If 't' is matching to the substring 
        {
            substring_size++;
            i++;
            j++;
        }
        if(substring_size == usize)                         // If we found the substring
        {
            cout << "Yes" << "\n";
            return 0;
        }       
        else if(substring_size != 0)                        // if not found (and a check to see if we even got into the while loop)    
        {
            i -= substring_size;
            substring_size = 0;
            j = 0;
        }
    }

    cout << "No" << "\n";
}