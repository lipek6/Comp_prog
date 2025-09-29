#include <iostream>
#include <vector>
#include <queue>

#define INSERT          0
#define GET_MAX         1
#define DELETE_MAX      2

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;              // number of priority queues in the vector
    std::cin >> n;
    
    int q;              // number of operations
    std::cin >> q;

    std::vector<std::priority_queue<int>> pq_vector(n);

    short op;   // insert, get max, delete max operations
    int t;      // priority queue index in the vector
    int x;      // value to insert case operation == insert

    while(q--)
    {
        std::cin >> op;
        std::cin >> t;

        if (op == INSERT)
        {
            std::cin >> x;
            pq_vector[t].push(x);
        }

        else if (op == GET_MAX && !pq_vector[t].empty())
        {
            std::cout << pq_vector[t].top() << "\n";
        }

        else if (op == DELETE_MAX && !pq_vector[t].empty())
        {
            pq_vector[t].pop();
        }

    }
}