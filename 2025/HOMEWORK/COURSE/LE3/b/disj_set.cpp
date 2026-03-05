#include <bits/stdc++.h>

struct disjoint_set
{
    int sets_amount;            // Current amount of sets
    int biggest_size;            // Size of the biggest set
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

int main (void)
{
    // A component is a group of cities where there is a route between any two cities using the roads == disjoint set union
    // Find the number of components and the size of the largest component

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, a, b;                 // Number of cities, number of roads, cities to connect by a road (a, b)
    std::cin >> n >> m;

    disjoint_set dsu;

    dsu.init(n); 
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;         // We will construct a road between these two cities
        dsu.union_find(a, b);
        // Print number of sets and size of the largest set
        int amount = dsu.count();
        int largest = dsu.biggest();
        std::cout << amount << " " << largest << std::endl;
    }
}