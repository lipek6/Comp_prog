#include<iostream>
#include<bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);  // Magic on the memory
    std::cin.tie(nullptr);                  // Magic on the memory part 2


    int i;  // Loop iterator 
    int n;  // Number of players
    int k;  // Initial points
    int q;  // Number of questions

    std::cin >> n >> k >> q;         // Gets input for n, k and q in one line
    
    
    int absolute_comp = q - k + 1;   // Number of times that a player appears needs to be greater than this in order to survive
    std::vector<int>  corrects(q);   // Vector that holds the A0 to Ai inputs
    std::vector<int>  freq(n, 0);    // Holds the amount of times something appeared on the A0 to Ai input    
    
    
    for (i = 0; i < q; i++)          // Loop to gather inputs of A0 to Ai
    {
        std::cin >> corrects[i];
    }



    if (absolute_comp > 0)           //If less than or equal to 0, everyone survived
    {
        for (i = 0; i < q; i++)
        {
            freq[corrects[i] - 1]++;
        }
    }
    else
    {
        std::fill(freq.begin(), freq.end(), absolute_comp);
    }

    // Printing output
    for (i = 0; i < n; i++)
    {
        if (freq[i] >= absolute_comp)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }
}