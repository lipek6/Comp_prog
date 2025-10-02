#include <iostream>
#include <queue>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int value;
    std::string operation;
    std::priority_queue<int> pq;

    while(true)
    {
        std::cin >> operation;
        
        if (operation == "end")
        {
            break;
        }
        else if (operation == "insert")
        {
            std::cin >> value; 
            pq.push(value);
        }
        else
        {
            std::cout << pq.top() << "\n";
            if(!pq.empty())
            {
                pq.pop();
            }
        }
    }
}