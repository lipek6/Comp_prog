#include<bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> EL;
vector<int> parents;
vector<int> comp_size;
int comp_amount;

int find(int& city)
{
    if(parents[city] == city) return city;

    return parents[city] = find(parents[city]);
}

void join(int city1, int city2)
{
    city1 = find(city1);
    city2 = find(city2);

    if(city1 == city2) return;

    if(comp_size[city1] < comp_size[city2]) swap(city1, city2);

    parents[city2] = city1;
    comp_size[city1] += comp_size[city2];
    
    comp_amount--;
    return;
}


// Classic minimum spanning tree problem
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cities, roads; cin >> cities >> roads;
    
    EL.resize(roads);
    parents.resize(cities + 1); iota(parents.begin()+1, parents.end(), 1);
    comp_size.assign(cities + 1, 1);
    comp_amount = cities;

    for(int i = 0; i < roads; i++)
    {
        int city1, city2, cost; cin >> city1 >> city2 >> cost;
        EL.push_back({cost, city1, city2});
    }

    sort(EL.begin(), EL.end());

    long long total_cost = 0;

    for(auto& [cost, city1, city2] : EL)
    {
        if(find(city1) == find(city2)) continue;
        join(city1, city2);
    
        total_cost += cost;
    }
    
    if(comp_amount > 1)
        cout << "IMPOSSIBLE\n";
    else
        cout << total_cost << "\n";
        
    return 0;
}