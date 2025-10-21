#include <iostream>
#include <bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;       // Tickets and costumers
    std::cin >> n;
    std::cin >> m;

    std::multiset <int, std::greater<int>> h;  // Tickets prices
    
    int entry;
    while(n--)
    {
        std::cin >> entry;
        h.insert(entry);
    }
    std::multiset<int>::iterator it = h.begin();
    
    while(m--)
    {
        std::cin >> entry;
        it = h.lower_bound(entry);

        if (h.find(*it) == h.end())
        {
            std::cout << "-1\n";
        }
        else
        {
            std::cout << *it << "\n";
            h.erase(it);
        }
    }
}