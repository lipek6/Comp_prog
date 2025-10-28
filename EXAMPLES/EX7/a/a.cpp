#include<bits/stdc++.h>
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

// We will use Kruskal's algorithm

// Edge list
vector<tuple<int, int, int>> EL;

string line  = "";
string line2 = "";


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true)
    {
        long long initial_cost = 0LL;
        long long new_cost     = 0LL;

        EL.clear();
        int n; 
        
        if(line2 == "") cin >> n;
        else n = stoi(line2);

        disjoint_set ds;
        ds.init(n);
        int u, v, w;
        for(int i = 0; i < n - 1; i++)
        {
            cin >> u >> v >> w;
            initial_cost += w; 
        }
        
        int k; cin >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> u >> v >> w;
            EL.push_back({w, u, v});
        }

        int m; cin >> m;        // Is this useless???
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;  
            EL.push_back({w, u, v});
        }

        // Applying Kruskal's Algorithm
        sort(EL.begin(), EL.end());
        for(int i = 0; i < EL.size(); i++)
        {
            int w = get<0>(EL[i]);
            int u = get<1>(EL[i]);
            int v = get<2>(EL[i]);

            if(ds.get(u) != ds.get(v))
            {
                new_cost += w;
                ds.union_find(u, v);
            }
        }
        cout << initial_cost << "\n" << new_cost << "\n";

        cin.ignore();
        getline(cin, line);
        getline(cin, line2);
        if(line == "" && line2 == "") break;
        else cout << "\n";
    }
}
