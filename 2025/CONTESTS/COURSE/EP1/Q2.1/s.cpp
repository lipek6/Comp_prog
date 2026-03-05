#include <iostream>
#include <bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::string stk;
    std::cin >> str;

    for (char c : str)
    {
        stk.push_back(c);
        if (stk.size() >= 3 && stk.substr(stk.size() - 3, 3) == "ABC")
        {
            stk.pop_back();
            stk.pop_back();
            stk.pop_back();
        }
    }
    std::cout << stk << "\n";




}