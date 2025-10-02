#include <bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, entry;
    std::cin >> n >> k;

    std::vector<int> x_input(n);
    std::vector< std::priority_queue<int, std::vector<int>, std::greater<int>>> x(n);       // Vector of min HEAPS
    for (int i = 0; i < n; i++)
    {
        std::cin >> entry;
        x_input[i] = entry;
    }
    for (int i = 0; i < n - k + 1; i++)
    {
        for(int j = 0; j < k; j++)
        {
            x[i].push(x_input[i+j]);
        }
    }
    for (auto it : x)
    {
        std::cout << it.top() << " ";
    }
}