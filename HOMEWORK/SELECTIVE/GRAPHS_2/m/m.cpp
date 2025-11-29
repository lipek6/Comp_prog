#include<bits/stdc++.h>
using namespace std;
vector<tuple<unsigned long long, unsigned long long, unsigned long long>> EL;
vector<unsigned long long> sizes;
vector<unsigned long long> p;
unsigned long long amount;

unsigned long long find(unsigned long long a)
{
    if(p[a] == a)
        return a;
    return p[a] = find(p[a]);
}

void join(unsigned long long a, unsigned long long b)
{
    a = find(a);
    b = find(b);

    // a needs to be always bigger
    if(sizes[a] < sizes[b]) swap(a ,b);

    p[b] = a;
    sizes[a] += sizes[b];
    amount--;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long n, m, k; cin >> n >> m >> k;
    
    p.resize(n+1); iota(p.begin(), p.end(), 0);
    sizes.assign(n+1, 1);
    EL.reserve(m);
    amount = n;

    for(int i = 1; i <= m; i++)
    {
        unsigned long long a, b, w; cin >> a >> b >> w;
        EL.push_back({w % k, a, b});
    }

    sort(EL.begin(), EL.end());

    unsigned long long total_weight = 0ULL;
    for(auto [w, a, b] : EL)
    {
        if(find(a) == find(b)) continue;
        total_weight += w % k;
        join(a, b);
        
        if(amount == 1) break;
    }

    cout << total_weight % k << "\n";
}