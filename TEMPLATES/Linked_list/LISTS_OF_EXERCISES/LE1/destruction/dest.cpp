#include<iostream>
#include<bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);  // Magic on the memory
    std::cin.tie(nullptr);                  // Magic on the memory part 2
    
    long long i;             // Loop iterator
    long long t;             // Amount of test cases
    long long n;             // Amount of fields
    long long entry;         // Input of how many dandelions in one field
    long long accumulator;   // Amount of dandelions harvesteds (we put everything in here, after that we remove what shouldn't be here)

    std::cin >> t;              // Gets the amount of test cases
    
    // Running while test cases
    while(t--)
    {
        std::cin >> n;                                 // Gets the amount of fields

        std::vector<long long> odds;                   // Odds inside inputs
        std::vector<long long>::iterator it;
        accumulator = 0;

        // Gets amount of dandelions per field and sorts it in odds, also put everything in the accumulator
        for (i = 0; i < n; i++)                     
        {
            std::cin >> entry;
            accumulator += entry;

            if(entry % 2 != 0)
            {
                odds.push_back(entry);
            }
        }
        
        // If he nevers can turn on his lawnmower
        if(odds.empty())
        {
            std::cout << 0 << "\n";
            continue;
        }

        std::sort(odds.begin(), odds.end());
        
        long long middle = std::ceil(odds.size()/2);
        
        for(i = 0; i < middle; i++)
        {
            accumulator -= odds[i];
        }

        std::cout << accumulator << "\n";
    }
}