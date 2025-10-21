#include<bits/stdc++.h>

// We wanna find two values that added results in x.
// It migth be interesting to order this with a heap / priority_queue
// With the things ordered, we can add top and last top.
// To save the indexes of the numbers, we will need to use a multimap
// We can try using two iterators, one at the end and one at the begining
// Remember that a multimap is sorted in ascending order based on the keys (in this case, the keys are the values and the values are the indexes)
// YES, if it1 + it2 == x, done; if < x, we advance it to get bigger; if less than x, we get it2-- to have lower values

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, ai;
    std::cin >> n >> x;
    std::multimap<int, int> a;       // Given value to address 

    for(int i = 1; i < n+1; i++)
    {
        std::cin >> ai;
        a.insert({ai, i});
    }
    
    auto it = a.begin();
    auto it2 = std::prev(a.end());
    
    while(true)
    {
        if(it == it2)
        {
            std::cout << "IMPOSSIBLE\n";
            break;
        }
        if(it->first + it2->first == x)
        {
            std::cout << it->second << " " << it2->second << "\n";
            break;
        }
        else if(it->first + it2->first > x)
        {
            it2--;
            continue;
        }
        else
        {
            it++;
            continue;
        }
    }
}