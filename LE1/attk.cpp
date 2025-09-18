#include <iostream>
#include <algorithm>

// I know it will have problems with time. TLE
int main (void)
{
    int n;  // Amount of players
    int k;  // Initial points
    int q;  // Number of questions
    int w;  // Winner of the match index

    scanf("%i %i %i", &n, &k, &q);

    int players[n];
    std::fill_n(players, n, k);
    
    // Analyze all the inputs first
    
    for (int i = 0; i < q; i++)
    {
        scanf("%i", &w);
        
        for(int j = 0; j < n; j++)
        {
            if (w - 1 != j)
            {
                players[j] = players[j] - 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(players[i] <= 0)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
}