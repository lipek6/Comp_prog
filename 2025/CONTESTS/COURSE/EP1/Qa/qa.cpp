#include <iostream>
#include <bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;

    std::cin >> str;
    int w = 0;

    for (std::string::iterator it = str.begin(); it != str.end(); it++)
    {
        if (*it == 'A')
        {
            w = 1;
            continue;
        }
        else if (w == 1 && *it == 'B')
        {
            w = 2;
            continue;
        }
        else if(w == 2 && *it == 'C')
        {
            str.erase(it);
            str.erase(it - 1);
            str.erase(it - 2);

            it = it - 6;
            w = 0;
            continue;
        }
        else
        {
            w = 0;
        }
    }
    std::cout << str << "\n";
}