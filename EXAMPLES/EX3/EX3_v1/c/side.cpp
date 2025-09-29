#include<iostream>
#include<bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    int n;
    int curr;
    int past;
    int x;
    int i = 0;
    std::priority_queue<int> a;

    std::cin >> t;

    while(t--)
    {
        std::cin >> n;
        while(n--)
        {
            std::cin >> curr;
            std::cin >> x;
            if (i > 2)
            {
                if (a.top() + curr > x || a.top() + x > curr || curr + x > a.top())
                {
                    a.pop();
                    a.push(x);
                    continue;
                }
                a.push(curr);        
                i++;
            }
        }
    }
}