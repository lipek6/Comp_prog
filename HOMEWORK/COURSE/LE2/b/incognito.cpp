#include <bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, n;
    long long result;
    std::string name, tag;                                         

    std::unordered_map<std::string, int> map;

    std::cin >> t;
    while(t--)
    {
        result = 1;
        map = {};
        std::cin >> n;
        while(n--)
        {
            std::cin >> name >> tag;
            map[tag]++;
        }
        
        for (auto i : map)
        {
            result *= i.second + 1;
        }

        std::cout << result - 1 << "\n";
    }
}