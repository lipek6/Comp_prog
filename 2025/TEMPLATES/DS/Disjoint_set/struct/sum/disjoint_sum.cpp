#include <bits/stdc++.h>

struct disjoint_set
{
    std::vector<int> r;             // Ranks
    std::vector<int> p;             // Parents
    std::vector<int> min;           // Minimals
    std::vector<long long> sum;     // Sums

    void init(int total_size)
    {
        for (int i = 0; i < total_size + 1; i++) // +1 to aviod 0 index problems
        {
            r.push_back(1);
            p.push_back(i);
            sums.push_back(i);
            min.push_back(i);
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

    void union_find(int a, int b)    // Union find with rank comparison
    {
        a = get(a); // Find the leader of a
        b = get(b); // Find the leader of b
        
        if(a == b)             // Avoid the case where we try to unite two elements into the same set
        {
            return;
        }

        if (r[a] == r[b])
        {
            r[a]++;
        }
        else if (r[a] > r[b])
        {
            p[b] = a;
            sum[a] += sum[b]
            min[a] = std::min(min[a], min[b]);
            return;
        }
        p[a] = b;
        sum[b] += sum[a];
        min[b] = std::min(min[a], min[b]);
        return;
    }
};

int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, u, v;
    std::string op;
    std::cin >> n >> m;
    
    disjoint_set dsu;
    dsu.init(n);
 
    for (int i = 0; i < m; i++)
    {
        std::cin >> op >> u >> v;
        if (op == "union")
        {
            dsu.union_find(u, v);
        }
        else
        {
            u = dsu.get(u);
            v = dsu.get(v);
            if (u == v)
            {
                std::cout << "YES\n";
            }
            else
            {
                std::cout << "NO\n";
            }
        }
    }
}