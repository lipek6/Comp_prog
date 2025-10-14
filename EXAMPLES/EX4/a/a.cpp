#include<bits/stdc++.h>



int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;           // Size of the group and amount of constraints
    int a, b, c;
    
    int valid;
    while(true)
    {
        std::cin >> n >> m;
        if(m == 0 && n == 0)
        {
            break;
        }
        
        int fact_n = 1;
        for(int i = 1; i < n + 1; i++)
        {
            fact_n = fact_n * i;
        }
    
        std::vector<std::vector<int>> all (fact_n, std::vector<int>(n, 0));        
        std::vector<int> group(n);
        for(int i = 0; i < n; i++)
        {
            group[i] = i;
        }

        for(int i = 0; i < fact_n; i++)
        {
            all[i] = group;
            std::next_permutation(group.begin(), group.end());
        }
        
        valid = fact_n;    
        std::vector<int> invalid;
        for(int i = 0; i < m; i++)
        {
            std::cin >> a >> b >> c;
            for(int j = 0; j < all.size(); j++)
            {
                int pos_a = -1;
                int pos_b = -1;
                for(int k = 0; k < n; k++)
                {
                    if(pos_a >= 0 && pos_b >= 0) break;
                    if (all[j][k] == a) pos_a = k;
                    if (all[j][k] == b) pos_b = k;
                }
                
                int dist = std::abs(pos_a - pos_b);
                
                if(c >= 0)
                {
                    if(dist > abs(c) && !std::count(invalid.begin(), invalid.end(), j))
                    {
                        invalid.push_back(j);
                        valid--;
                    }
                }
                else
                {
                    if(dist < abs(c) && !std::count(invalid.begin(), invalid.end(), j))
                    {
                        invalid.push_back(j);
                        valid--;
                    }
                }
            }
        }
        std::cout << valid << "\n";
    }
}