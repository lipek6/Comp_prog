#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> x(n);

    // Multiset to sort this shit
    multiset<int> up;
    multiset<int> dw;
    
    int max_dw = (k + 1) / 2;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        
        if (dw.empty() || x[i] <= *dw.rbegin())
            dw.insert(x[i]);
        else
            up.insert(x[i]);


        // Whiles to balance the multisets
        while(dw.size() > max_dw)
        {
            up.insert(*dw.rbegin());    // I wanna the person who decided to mess the .end() of a multiset to burn in hell
            dw.erase(dw.find(*dw.rbegin()));
        }

        while(dw.size() < max_dw && !up.empty())
        {
            dw.insert(*up.begin());
            up.erase (up.find(*up.begin()));
        }


        if(i >= k - 1)
        {
            cout << *dw.rbegin() << " ";    // PRINT

            if(x[i - k + 1] > *dw.rbegin())         // Remove fucker that got out of the window
                up.erase(up.find(x[i - k + 1]));
            else
                dw.erase(dw.find(x[i - k + 1]));
        }    

        // Rebalancing again
        while(dw.size() > max_dw)
        {
            up.insert(*dw.rbegin());    // I wanna the person who decided to mess the .end() of a multiset to burn in hell
            dw.erase(dw.find(*dw.begin()));
        }

        while(dw.size() < max_dw && !up.empty())
        {
            dw.insert(*up.begin());
            up.erase (up.find(*up.begin()));
        }
    }
    cout << "\n";
}