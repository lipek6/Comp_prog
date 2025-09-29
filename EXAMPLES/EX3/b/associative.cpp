#include<bits/stdc++.h>

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int Q;
    long long k;
    long long v;
    bool cmd;
    std::map<long long, long long> a;

    std::cin >> Q;
    while(Q--)
    {
        std::cin >> cmd;
        std::cin >> k;
  
        if (cmd == 1)
        {
            std::cout << a[k] << "\n";
        }
        else
        {
            std::cin >> v;
            a[k] = v;
        }
    }
}