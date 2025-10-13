#include<bits/stdc++.h>

int fact(int n)
{
    int fact_n = 1;
    for(int i = 1; i < n+1; i++)
    {
        fact_n = fact_n * i;
    }  
    return fact_n;
}

std::vector<int> available_people(int n)
{
    std::vector<int> teens(n);
    for (int i = 0; i < n; i++)
    {
        teens[i] = i;
    }
    return teens;
}


int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, c;
    int n, m;           // Size of the group and amount of constraints
    while(true)
    {
        std::cin >> n >> m;
        if(m == 0 && n == 0)
        {
            break;
        }

        std::vector<int> group(n);
        for(int i = 0; i < n; i++)
        {
            group[i] = i;
        }

        std::vector<std::vector<int>(n)> tree(n);
        int depth = 0;
        for(int i = 0; i < n; i++)
        {
            tree[i][depth] = group[i];
            depth++;
            for(int j = 0; j < n - depth; j++)
            {
                tree[i][j + depth] = group[j + depth];
                depth++;
                for(int k = 0; k < n - depth; k++)
                {
                    tree[i][k + depth] = group[k + depth];
                }

            }
        }

        while(m--)
        {
            std::cin >> a >> b >> c;
            
        }
    }







}