#include<bits/stdc++.h>
using namespace std;
// minimum range necessary so that it is possible for the car to travel between any two cities on the continent.
// We want a minimun spanning tree
vector<tuple<int, int, int>> EL;

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

    int n, m;

    while(cin >> n >> m)
    {
        if(n == 0 && m == 0) break;
    
        EL.clear();
        disjoint_set dsu;
        dsu.init(n);
        
        for(int i = 0; i < m; i++)
        {
            int u, v, w; cin >> u >> v >> w;
            EL.push_back({w, u, v});
        }
        sort(EL.begin(), EL.end());


        int range = 0;

        // Applying Kruskal's Algorithm
        for(int i = 0; i < EL.size(); i++)
        {
            int w = get<0>(EL[i]); 
            int u = get<1>(EL[i]);
            int v = get<2>(EL[i]);

            if(dsu.get(u) != dsu.get(v))
            {
                range = max(range, w);
                dsu.union_find(u, v);
            }
        }
        if(dsu.sets_amount > 1) cout << "IMPOSSIBLE\n";
        else cout << range << "\n";

    }


}