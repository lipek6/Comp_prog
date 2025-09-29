#include<iostream>
#include<bits/stdc++.h>

int main (void)
{
    unsigned int i;     // Loop iterator
    unsigned int t;     // Amount of test cases
    unsigned int n;     // Amount of fields
    unsigned int accumulator;   // Amount of dandelions harvesteds
    bool lawn = 0;

    std::cin >> t;
    
    // Running while test cases
    while(t--)
    {
        std::cin >> n;

        std::vector<unsigned int> a(n);     // Original input vector
        std::vector<unsigned int> evens(n); // Evens inside original vector
        std::vector<unsigned int> odds (n); // Odds inside original vector
        std::vector<unsigned int> sorted_a (n);

        for (i = 0; i < n; i++)     // Gets amount of dandelions per field
        {
            std::cin >> a[i];        
        }

        for (i = 0; i < n; i++)      // Sorts Evens and Odds
        {
            if (a[i] % 2 == 0)
            {
                evens.push_back(a[i]);
            }
            else
            {
                odds.push_back(a[i]);
            }   
        }

        sorted_a[0] = odds[0];
        odds.erase(odds.begin());

        for (i = 0; i < sizeof(evens); i++)
        {
            sorted_a.push_back(evens[i]);
        }
        for (i = 0; i < sizeof(odds); i++)
        {
            sorted_a.push_back(odds[i]);
        }

        for (i = 0; i < n; i++)
        {
            if (sorted_a[i] % 2 != 0 && lawn == 0)
            {
                lawn = 1;
            }
            else if (sorted_a[i] % 2 != 0 && lawn == 1)
            {
                lawn = 0;
            }
            
            if(lawn == 1)
            {
                accumulator += sorted_a[i];
            }
        }
        std::cout << accumulator << std::endl;
    }
}