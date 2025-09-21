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
    int w_counter; // Holds the amount of times a person appeared on the A0 to Ai input

    std::cin >> n >> k >> q;         // Gets input for n, k and q in one line
    
    
    int absolute_comp = q - k + 1;   // Number of times that a player appears needs to be greater than this in order to survive
    std::vector<int>  corrects(q);   // Vector that holds the A0 to Ai inputs
    std::vector<bool> survived(n);   // If 1, player survived; If 0, player lost
    std::vector<int>  count_controller(q);   // If something has already been counted, it is stored here to avoid recounting
    
    
    
    for (i = 0; i < q; i++)          // Loop to gather inputs of A0 to Ai
    {
        std::cin >> corrects[i];
    }



    if (absolute_comp > 0)           //If less than or equal to 0, everyone survived
    {
        std::fill(survived.begin(), survived.end(), 0);
        for (i = 0; i < q; i++)
        {
            // Check if the element has already been counted (idk why, but "find" has a pretty odd return value instead of a bool)
            if(std::find(count_controller.begin(), count_controller.end(), corrects[i]) != count_controller.end())
            {
                continue;
            }
            
            count_controller.push_back(corrects[i]);    // Putting what is been countend on the list of counted things
            w_counter = std::count (corrects.begin(), corrects.end(), corrects[i]);
            
            if (absolute_comp <= w_counter)
            {
                survived[corrects[i] - 1] = 1;
            }
        }
    }
    else
    {
        std::fill(survived.begin(), survived.end(), 1);
    }

    // Printing output
    for (i = 0; i < n; i++)
    {
        if (survived[i] == 1)
        {
            std::cout << "Yes\n";
        }
        else
        {
            std::cout << "No\n";
        }
    }
}