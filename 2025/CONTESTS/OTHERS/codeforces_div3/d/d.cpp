#include<bits/stdc++.h>
#define UNVISITED 1e9
using namespace std;

struct disjoint_set
{
    std::vector<int> s;     // Sizes
    std::vector<int> p;     // Parents
    int sets_amount;
    void init(int total_size)
    {
        for (int i = 0; i < total_size + 1; i++) // +1 to aviod 0 index problems
        {
            s.push_back(1);
            p.push_back(i);
        }
        sets_amount = total_size;
        return;
    }

    int get(int a)  // Get wi\th path compression
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
        
        if(a == b)                     // Avoid the case where we try to unite two elements into the same set
        {
            return;
        }
        sets_amount--;

        if(s[a] > s[b])           // Make sure that we will unite the smaller whit the larger
        {
            int temp = a;
            a = b;
            b = temp;
        }
        p[a] = b;
        s[b] += s[a];
        return;
    }
};

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc; cin >> tc;

    while(tc--)
    {
        int n; cin >> n;

        vector<int> p(n+1);        
        for(int i = 1; i <= n; i++) cin >> p[i];

        disjoint_set ds;
        ds.init(n+1);
        
        for(int i = n; i >= 1; i--)
        {
            for(int j = i; j >= 1; j--)
            {
                
                if(p[i] > p[j])
                {
                    ds.union_find(i, j);
                }
            }
        }

        if (ds.sets_amount > 2)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}