#include<bits/stdc++.h>

// We have orbits (buckets) to put the plantes, we can use a map!
// Compare the amount of planets in a bucket with c, if c is less, c = answer, else, count = answer;
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;  // Test cases
    int n;  // Amount of planets
    int c;  // Second machine cost
    int a;  // A planet orbit
    int cost = 0;

    std::unordered_map<int, int> orbits;
    std::cin >> t;
    while(t--)
    {
        orbits = {};        // REMEMBER TO CLEEEAN
        cost = 0;           // REMEMBER TO CLEEEAN
        std::cin >> n >> c;
        while(n--)
        {
            std::cin >> a;
            orbits[a]++;
        }

        for(auto orbit : orbits)
        {
            if(c <= orbit.second)
            {
                cost += c;
            }
            else
            {
                cost += orbit.second;
            }
        }
        std::cout << cost << "\n";
    }
}