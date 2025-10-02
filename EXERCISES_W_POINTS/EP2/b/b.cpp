#include<bits/stdc++.h>

// We wanna put the smallest box into the second smallest box into the third smallest box...
// It kinda looks like a heap / priority_queue (min) where we will store the top, compare the
// stored top with the current top, if the current top is bigger, we put the box in it and visible boxes--
// else, because everything is ordered, we break, there is nothing else to do than printing the current amount
// of visible boxes.

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;              // Number of boxes
    long long ai;             // Current box
    std::cin >> n;
    long long visibles = n;   // Amout of visible boxes
    
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> a;

    while(n--)
    {
        std::cin >> ai;
        a.push(ai);
    }

    int last_top;
    
    while(a.size() > 1)
    {
        last_top = a.top();
        a.pop();

        if(a.top() > last_top)
        {
            visibles--;
        }
        else
        {
            if (a.top() == last_top)
            {
                visibles--;
                continue;   
            }
            break;
        }
    }
    std::cout << visibles << "\n";
}