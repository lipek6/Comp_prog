#include<bits/stdc++.h>

// Segment tree
struct segtree 
{

    int size;
    std::vector<long long> sums;
    
    // Initialize the segment tree method
    void init(int n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
            sums.assign(2*size, 0LL);
        }
    }

    // Build the segment tree in linear time
    void build (int a)
    {




    }

    // Set a element to a value method
    void set (int i, int v, int x, int lx, int rx) // i(index), v(value), c(current node), lx(left node), rx(right node)
    {
        if(rx - lx == 1) // Leaf (bottom of the tree)
        {
            sums[x] = v;
            return;
        }
        int m = (lx + rx) / 2;  // Middle of the segment
        if (i < m)
        {             //Left   
            set(i, v, 2 * x + 1, lx, m);
        }
        else 
        {
            set(i, v, 2 * x + 2, m, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set (int i, int v)
    {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx)
    {
        if(lx >= r || rx <= l)
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



int main (void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;           // Size of the array and number of operations
    std::cin >> n >> m;

    segtree st;
    std::vector<int> a(n);
    st.init(n);
    for (int i =0; i < n; i++)
    {
        std::cin >> a[i];
    }
    st.build(a);

    while(n--)
    {
        int op;
        std::cin >> op;
        if(op == 1)
        {
            int i, v;
            std::cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r;
            std::cin >> l >> r;
            std::cout << st.sum(l, r) << "\n";
        }
    }
}