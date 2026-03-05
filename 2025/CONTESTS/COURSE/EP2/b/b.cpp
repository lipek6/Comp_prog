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

    int n;
    int ai;
    int last_top;
    std::priority_queue<int, std::vector<int>, std::greater<int>> a;
    std::queue<int> queue_equals;
    std::cin >> n;
    int visibles = n;
    


    while(n--)
    {
        std::cin >> ai;
        a.push(ai);
    }
    
    while(a.size() != 1)
    {
        last_top = a.top();
        a.pop();
    
        if(last_top < a.top())
        {
            visibles--;
        }
    
        else if(last_top == a.top())
        {
            queue_equals.push(last_top);
            if (!queue_equals.empty())
            {
                if (queue_equals.front() < a.top())
                {
                    queue_equals.pop();
                    visibles--;
                }
            }
        }
    
        else
        {
            break;
        }
    }

    std::cout << visibles << "\n";
}