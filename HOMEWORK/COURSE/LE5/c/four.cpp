#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // We want the minimum cost. It can be greedy or dp, but it is probably dp
    
    // Using a greedy algorithm, we can look at the cost per person of each car and put the students
    // on the cars from the lowest to the biggest cost per person
    
    int x, n; cin >> x >> n;           // Number of marathonists and available ride options

    vector<int> p(n);       // Passengers
    vector<int> v(n);       // Values
    for(int i = 0; i < n; i++)
    {
        cin >> p[i] >> v[i];        // Number of passengers and the charge for the trip
    }

    vector<int>dp(n)
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dp[i] = v[j]

        }   
    }


}