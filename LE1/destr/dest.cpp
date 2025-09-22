#include<iostream>
#include<bits/stdc++.h>

int main (void)
{
    unsigned int i;             // Loop iterator
    unsigned int t;             // Amount of test cases
    unsigned int n;             // Amount of fields
    unsigned int entry;         // Input of how many dandelions in one field
    unsigned int accumulator;   // Amount of dandelions harvesteds
    bool lawn = 0;

    std::cin >> t;              // Gets the amount of test cases
    
    // Running while test cases
    while(t--)
    {
        std::cin >> n;                               // Gets the amount of fields

        std::list<unsigned int> evens;               // Evens inside inputs
        std::list<unsigned int> odds;                // Odds inside inputs
        std::vector<unsigned int> big_odds;          // Big Odds inside inputs
        std::vector<unsigned int> little_odds;       // Little Odds inside inputs

        std::list<unsigned int> sorted_a;            // Will have the a vector in optimal order
        std::list<unsigned int>::iterator it;
        unsigned int small_odd = UINT_MAX;           // Smaller odd number of the dandelions inputs 

        
        // Gets amount of dandelions per field and sorts it in evens an odds
        for (i = 0; i < n; i++)                     
        {
            std::cin >> entry;
            if(entry % 2 == 0)
            {
                evens.push_back(entry);
            }
            else
            {
                if(entry < small_odd)
                {
                    small_odd = entry;
                }
                odds.push_back(entry);
            }
        }
        
        // If he nevers can turn on his lawnmower
        if(odds.empty())
        {
            std::cout << accumulator << "\n";
            continue;
        }
        
        sorted_a.push_back(small_odd);

        //[3, 6, 2, 1]
        if(n % 2 == 0)
        {


        }
        //[5, 9, 2]
        else
        {


        }
        sorted_a.push_back


    }
}