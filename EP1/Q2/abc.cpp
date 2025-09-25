#include <iostream>
#include <bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string og_str;
    std::string nw_str;

    std::cin >> og_str;

    for (char c : og_str)
    {
        nw_str.push_back(c);
        if (nw_str.size() >= 3 && nw_str.substr(nw_str.size()-3, 3) == "ABC")
        {
            nw_str.pop_back();
            nw_str.pop_back();
            nw_str.pop_back();
        }
    }
    std::cout << nw_str << "\n";
}

//BAABCBCCABCAC
//BAABC