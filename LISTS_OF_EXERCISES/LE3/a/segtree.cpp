#include<bits/stdc++.h>

struct segtree
{
    int size;
    std::vector<long long> sums;

    void init(int n)
    {
        size = 1;
        while(size < n) 
        {
            size *= 2;              // Guarantee that the size of the tree is a power of two
        }
        sums.assign(2 * size, 0LL); // The size of the tree is the double of the array size (considering the power of 2)
    }

    // Recursive build
    void build (std::vector<int> &a, int x, int lx, int rx)
    {
        // REMEMBER lx is included and rx is excluded
        if (rx - lx == 1)           // Check if the segment size is 1 (a leaf)
        {
            if (lx < (int)a.size()) // Check if the index is in the original array or is just to satisfy a power of 2
            {
                sums[x] = a[lx];
            }
            return;
        }

        // Dive and conquer
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m); // Left side
        build(a, 2 * x + 2, m, rx); // Right side
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2]; // Calculates the parent value
    }

    void build(std::vector<int> &a)
    {
        build(a, 0, 0, size);
    }

    // Recursive set
    void set(int k, int u, int x, int lx, int rx)
    {
        if(rx - lx == 1) // leaf
        {
            sums[x] = u;
            return;
        }
        int m = (lx + rx) / 2;
        if (k < m)
        {
            set(k, u, 2 * x + 1, lx, m);    // Go left
        }
        else
        {
            set(k, u, 2 * x + 2, m, rx);    // Go right
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];

    }

    void set(int k, int u)
    {
        set(k, u, 0, 0, size);
    }
    
    // Recursive sum
    long long sum(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l) // Missed
        {
            return 0;
        }
        if (lx >= l && rx <= r)
        {
            return sums[x];
        }
        
        int m = (lx + rx) / 2;
        long long s1 = sum(l, r, 2 * x + 1, lx, m);
        long long s2 = sum(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }
    
    long long sum(int l, int r)
    {
        return sum(l, r, 0, 0, size);
    }
    
};
// Guarantee that the size of the tree is a power of two
int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    segtree sg;
    int n;                  // Initial array size
    int q;                  // Amount of queuries
    std::cin >> n >> q;
    
    std::vector<int> a(n);  // Initial array


    sg.init(n);         // Itialization of the segtree accord to the size
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    sg.build(a);        // Building the segtree from the given array


    while(q--)
    {
        int op;
        std::cin >> op;
        if(op == 1)
        {
            int k, u;
            std::cin >> k >> u;
            sg.set(k-1, u);
        }
        else
        {
            int l, r;
            std::cin >> l >> r;
            std::cout << sg.sum(l-1, r) << "\n";
        }
    }

}