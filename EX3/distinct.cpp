#include<bits/stdc++.h>

int main (void)
{
    int n;
    std::cin >>  n;
    std::set<int> s;
    int a;
    while(n--)
    {
        std::cin >> a;
        s.insert(a);
    }

    std::cout << s.size();



}