#include<bits/stdc++.h>

struct disjoint_set
{
    int sets_amount;            // Current amount of sets
    int biggest_size;           // Size of the biggest set
    std::vector<int> s;         // Sizes
    std::vector<int> p;         // Parents

    void init(int total_size)
    {
        for (int i = 0; i < total_size + 1; i++) // +1 to aviod 0 index problems
        {
            s.push_back(1);
            p.push_back(i);
        }
        sets_amount = total_size;
        
        if (sets_amount > 0)
        {
            biggest_size = 1;
        }
        else
        {
            biggest_size = 0;
        }
        
        return;
    }

    int get(int a)  // Get with path compression
    {
        if (p[a] != a)
        {
            return p[a] = get(p[a]);
        }
        return a;
    }

    void union_find(int a, int b)    // Union find with size comparison
    {
        a = get(a); // Find the leader of a
        b = get(b); // Find the leader of b
        
        if(a == b)             // Avoid the case where we try to unite two elements into the same set
        {
            return;
        }
        sets_amount--;

        if(s[a] > s[b])   // Make sure that we will unite the smaller whit the larger
        {
            p[b] = a;
            s[a] += s[b];
            if(biggest_size < s[a])
            {
                biggest_size = s[a];
            }
            return;
        }
        
        p[a] = b;
        s[b] += s[a];
        if(biggest_size < s[b])
        {
            biggest_size = s[b];
        }
        return;
    }

    int size(int a)
    {
        return s[get(a)];
    }

    int count()
    {        
        return sets_amount;
    }

    int biggest()
    {
        return biggest_size;
    }
};

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    disjoint_set dsu;
    int n, m, x, y;       // Chemicals and pairs and to put (x, y)
    std::vector<std::pair<int, int>> pairs;
    int danger = 1;
    std::cin >> n >> m;

    dsu.init(n);
    while(m--)
    {
        std::cin >> x >> y;
        pairs.push_back({x, y});
        dsu.union_find(x, y);
    }

    for (int i = 0; i < dsu.size(dsu.biggest()) - 1; i++)
    {   
        if(dsu.get(pairs[i].first) == dsu.get(pairs[i].second))
        {
            danger *= 2; 
        }
    }
    std::cout << danger << std::endl;
}