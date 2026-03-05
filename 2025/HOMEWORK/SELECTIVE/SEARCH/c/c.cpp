#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long k;
    int n, m; cin >> n >> m >> k;    // "The number of applicants, the number of apartments, and the maximum allowed difference"

    multiset<long long> a;
    for(int i = 0; i < n; i++)
    {
        long long ai; cin >> ai;
        a.insert(ai);
    }

    vector<long long> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b.begin(), b.end());

    
    // Doing a BS for each apartment to find the best applicant for it
    // The guys are getting multiple apartments, so I need to erase them from the vector
    // Erase is lame, so I will adopt a multiset, but multisets have a not fun binary search :(
    
    int people_apartment = 0;
    for(int i = 0; i < m; i++) // Loop for apartments
    {
        // Gets the apartment bigger or equal to what the guy accepts
        auto lower_ap = a.lower_bound(b[i] - k);
        
        if(lower_ap == a.end()) continue;           
    
        if(abs(*lower_ap - b[i]) <= k)
        {
            // I am not searching in b, I don't need to touch this shit
            a.erase(lower_ap);
            people_apartment++;
        }
    }
    cout << people_apartment << "\n";
}