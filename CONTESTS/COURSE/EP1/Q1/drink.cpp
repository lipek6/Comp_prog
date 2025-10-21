#include <iostream>
#include <bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long i;                // Loop iterator
    long long n;                // Number of shops
    long long q;                // Number of days
    long long coins;            // Coins of the day
    long long can_buy;          // Amount of shops where he can buy

    std::cin >> n;              // Number of shops
    std::vector<long long>x(n); // Ith shop  drink price

    for (i = 0; i < n; i++)
    {
        std::cin >> x[i];       // Ith shop  drink price
    }

    std::sort(x.begin(), x.end());

    std::cin >> q;              // Number of days
    
    for (i = 0; i < q; i++)
    {
        std::vector<long long>::iterator up;
        can_buy = 0;

        std::cin >> coins; // Number of coins of the day

        up = std::upper_bound (x.begin(), x.end(), coins); 

        can_buy += (up - x.begin());      

        std::cout << can_buy << std::endl;
    }

}