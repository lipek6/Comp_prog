#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> EL;

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

// Classic minimum spanning tree problem
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    
    disjoint_set dsu;
    dsu.init(n);
    
    EL.resize(m, vector<int>(3));
    for(int i = 0; i < m; i++) cin >> EL[i][1] >> EL[i][2] >> EL[i][0];
    sort(EL.begin(), EL.end());

    long long cost = 0;
    for(int i = 0; i < EL.size(); i++)
    {
        if(dsu.get(EL[i][1]) != dsu.get(EL[i][2]))
        {
            dsu.union_find(EL[i][1], EL[i][2]);
            cost += EL[i][0];
        }
    }
    if(dsu.sets_amount > 1)
        cout << "IMPOSSIBLE" << "\n";
    else
        cout << cost << "\n";
}