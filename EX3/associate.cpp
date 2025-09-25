#include<iostream>
#include<bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    bool io; 

    long long n;
    long long a;  //value
    long long k;  //position

    std::map<long long, long long> m;
    
    std::cin >> n;
    
    while(n--)
    {
        std::cin >> io;

        if (io == 1)
        {
            std::cin >> k;
            std::cout << m[k] << "\n";
        }
        else
        {
            std::cin >> k;
            std::cin >> a;
            m[k] = a;
        }
    }
}