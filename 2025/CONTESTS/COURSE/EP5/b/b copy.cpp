#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;       //Amount of rocks / target and how many hops can be done at one time (maximum)
    cin >> n >> k;
    vector<int> h(n + 1);
    
    for(int i = 1; i < n + 1; i++) cin >> h[i];
    
    vector <int> dp_cost(n+1);
    vector <int> dp_ways(n+1);
    
    int total_cost = 0;
    dp_cost[1] = 0;
    dp_ways[1] = 1;

    if(n > 1)
    {
        dp_cost[2] = abs(dp_cost[1] - h[2]);
        dp_ways[2] = 0 + 1;
    }

    int i = 1;
    while(i != n)
    {
        pair<int, int> min_cost = {1000000, i};
        int j = i + 1;
        for(; j < i + k; j++)
        {
            dp_cost[j] = abs(dp_cost[i] - dp_cost[j]);
            dp_ways[j] = i - j;
            int cost = abs(h[i] - h[j]);
            if (cost < min_cost.first || (n - k)/k <= min_hops + k)
            {
                min_cost.first  = cost;
                min_cost.second = j; 
            }
        }
        if (j == n)
        {
            total_cost += abs(h[i] - h[n]);
            i = n;
        }
        else
        {
            total_cost += min_cost.first;
            i = min_cost.second;
        }
    }
    cout << total_cost << endl;
}
