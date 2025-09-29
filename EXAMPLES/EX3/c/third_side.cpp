#include<bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    int n;
    int entry;
    int a, b, min;
    
    std::cin >> t;
    while(t--)
    {
        std::priority_queue<int> heap;
        std::cin >> n;
        while(n--)
        {
            std::cin >> entry;
            heap.push(entry);
        }
        while(heap.size() > 1)
        {
            a = heap.top();
            heap.pop();

            b = heap.top();
            heap.pop();

            min = a + b - 1;
            heap.push(min);
        }
        std::cout << heap.top() << std::endl;
    }




}