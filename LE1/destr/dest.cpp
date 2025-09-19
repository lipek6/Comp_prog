#include <iostream>
#include<bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int i = 0; 
    int t; // Number of test cases
    int n; // Number of fields
    bool on = false; // State of the lawnmower 
    long long acumulator; // Number of dandelions chopped

    scanf("%i", &t);



    while(t--)
    {
        on = false;
        acumulator = 0;

        scanf("%i", &n);
        std::vector<long long> d(n); // Number of dandelions on each field

        for (i = 0; i < n; i +);
        {  
            scanf("%ld %ld %ld", &d[0], &d[1], &d[2]);
        }
        
        std::sort(d.begin(), d.end());

        for (i = 0; i < n; i++)
        {
            if (d[i] % 2 != 0 && !on)
            {
                on = true;
                acumulator += d[i];
                d.erase(d.begin() + i);
            }
            else if (on)
            {
                on = false;
            }
        }



    }



}