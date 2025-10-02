#include<bits/stdc++.h>

// We wanna find two values that added results in x.
// It migth be interesting to order this with a heap / priority_queue
// With the things ordered, we can add top and last top.
// If equals x, print that, if less than x, discard and keep going, if bigger than x, it is IMPOSSIBLE
// To save the indexes of the numbers, we will need another data structure

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x, ai, last_top, sum;
    std::cin >> n >> x; // array size and target sum

    std::multiset<int> a;
    std::vector<int> idxs;

    while(n--)
    {
        std::cin >> ai;
        idxs.insert(ai);
        a.insert(ai);
    }

    while(true)
    {
        last_top = a.begin();
        a.pop();

        sum = last_top + a.top();
        if(sum > x)
        {
            std::cout << "IMPOSSIBLE\n";
            break;
        }
        else if(sum == x)
        {
            std::cout << s << v << "\n";
            break;
        }
        else
        {
            a.pop();
            a.push(last_top);
            continue;
        }
    }
}