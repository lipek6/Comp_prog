#include<bits/stdc++.h>


int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int value;
    std::cin >> n;

    std::set<int> x;
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> value;
        x.insert(value);
    }
    std::cout << x.size();
}