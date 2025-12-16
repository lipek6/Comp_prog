#include<bits/stdc++.h>
using namespace std;

struct disjoint_set
{
    int sets_amount;           
    vector<int> s;        
    vector<int> p;         
    void init(int total_size)
    {
        for (int i = 0; i < total_size + 1; i++) 
        {
            s.push_back(1);
            p.push_back(i);
        }
        sets_amount = total_size;
                
        return;
    }

    int find(int a) 
    {
        if (p[a] == a)
            return a;
        return p[a] = find(p[a]);
    }

    void union_find(int a, int b)
    {
        a = find(a);
        b = find(b);
        
        if(a == b) return;

        sets_amount--;

        if(s[a] > s[b]) swap(a, b);
        
        p[a] = b;
        s[b] += s[a];
        return;
    }

    int count() {return sets_amount;}
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;

    disjoint_set dsu; dsu.init(n);
    vector<pair<int, int>> react_with;
    long long danger = 1LL;

    for(int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        react_with.push_back({x, y});
        dsu.union_find(x, y);
    }

    // What matters is the amount of connected components, and not what is inside these guys
    danger = danger << (n - dsu.count());       // Using bit shift

    cout << danger << "\n";
}