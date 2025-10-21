#include<bits/stdc++.h>
using namespace std;

// It was dp and I though it was greedy :(
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+Ki+1,i+2,…,i+K. 
    // Here, a cost of ∣hi−hj∣∣hi​−hj​∣ is incurred, where jj is the stone to land on.

    // Find the minimum possible total cost incurred before the frog reaches Stone N.


    int n, k;       //Amount of rocks/target and how many hops can be done at one time (maximum)
    cin >> n >> k;
    vector<int> h(n + 1);
    
    for(int i = 1; i < n + 1; i++) cin >> h[i];

    int total_cost = 0;
    int i = 1;
    while(i != n)
    {
        pair<int, int> min_cost = {1000000, i};
        int j = i + 1;
        
        if (j == i + k)
        {
            min_cost.first  = abs(h[i] - h[j]);
            min_cost.second = j; 
        }

        for(; j < i + k; j++)
        {
            int cost = abs(h[i] - h[j]);
            if (cost < min_cost.first)
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
