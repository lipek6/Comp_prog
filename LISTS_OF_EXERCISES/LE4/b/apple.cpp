#include <bits/stdc++.h>

int n;                                // Number of apples
long long min = LLONG_MAX;            // Minimal difference

std::vector<long long>  p(30);        // Weight of an apple

void solver (int i, long long sum_a, long long sum_b)
{    
    if(i >= n)
    {
        long long diff = std::abs(sum_a - sum_b);
        if (diff < min) min = diff;
        return;
    }

    long long weight = p[i];
    solver(i+1, sum_a + weight, sum_b);
    solver(i+1, sum_a, sum_b + weight);    
}


int main (void)
{
    // Divide the apples so that the difference of the weight of G1 - G2 is minimal
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    
    std::cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i];
    }

    solver(0, 0LL, 0LL);

    std::cout << min << "\n";
}