#include<bits/stdc++.h>

struct segtree
{
    int size;
    std::vector<int> mins;

    void init(int n)
    {
        size = 1;
        while(size < n) 
        {
            size *= 2;              // Guarantee that the size of the tree is a power of two
        }
        mins.assign(2 * size, -1LL); // The size of the tree is the double of the array size (considering the power of 2)
    }

    // Recursive build
    void build (std::vector<int> &a, int x, int lx, int rx)
    {
        // REMEMBER lx is included and rx is excluded
        if (rx - lx == 1)           // Check if the segment size is 1 (a leaf)
        {
            if (lx < (int)a.size()) // Check if the index is in the original array or is just to satisfy a power of 2
            {
                mins[x] = a[lx];
            }
            return;
        }

        // Dive and conquer
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m); // Left side
        build(a, 2 * x + 2, m, rx); // Right side
        int ml = mins[2 * x + 1] ;
        int mr = mins[2 * x + 2]; // Calculates the parent value
        if (ml < mr)
        {
            mins[x] = ml;
        }
        else
        {
            mins[x] = mr;
        }
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
            mins[x] = u;
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
        int ml = mins[2 * x + 1] ;
        int mr = mins[2 * x + 2]; // Calculates the parent value
        if (ml < mr)
        {
            mins[x] = ml;
        }
        else
        {
            mins[x] = mr;
        }

    }

    void set(int k, int u)
    {
        set(k, u, 0, 0, size);
    }
    
    // Recursive sum
    long long min(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || rx <= l) // Missed
        {
            return 9999999999999;
        }
        if (lx >= l && rx <= r)
        {
            return mins[x];
        }
        
        int m = (lx + rx) / 2;
        long long m1 = min(l, r, 2 * x + 1, lx, m);
        long long m2 = min(l, r, 2 * x + 2, m, rx);
        if (m1 < m2)
        {
            return m1;
        }
        else
        {
            return m2;

        }
    }
    
    long long min(int l, int r)
    {
        return min(l, r, 0, 0, size);
    }
    
};

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int n, q;    
    std::cin >> n >> q;
    
    std::vector<int> a(n);

    segtree sg;
    sg.init(n);                 // Itialization of the segtree accord to the size
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    sg.build(a);                // Building the segtree from the given array


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
            std::cout << sg.min(l-1, r) << std::endl;
        }
    }

}