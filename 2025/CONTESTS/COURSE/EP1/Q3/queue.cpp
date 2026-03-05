#include <iostream>
#include <bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int i;  // Loop iterator
    int j;  // Time counter
    int t;  // Test cases
    int n;  // Number of students
    int l;  // second ith student gets on the queue
    int r;  // second ith student gets out of the queue

    std::cin >> t;
    std::queue<int> in_line;
    std::queue<int> out_line;

    while(t--)
    {
        in_line = std::queue<int>();
        out_line = std::queue<int>();
        std::cin >> n;
        
        j = 0;
        for (i = 0; i < n; i++)
        {
            std::cin >> l;
            std::cin >> r;
            in_line.push(l);
            out_line.push(r);

            while(j < in_line.front())
            {
                j++;
            }

            if(out_line.front() >= j)   // Still waiting
            {
                std::cout << j << " ";
                in_line.pop();
                out_line.pop();
                j++;
            }

            else                        // No longer waiting
            {
                std::cout << "0" << " ";
                in_line.pop();
                out_line.pop();
            }
        }
        std::cout << "\n";
    }
}