#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--)
    {
        int n, c; cin >> n >> c;        // Planets, cost of the cool machine
        int furthest_orbit = 0;

        vector<int> orbit(101, 0);
        for(int i = 0; i < n; i++)
        {
            int planet_orbit; cin >> planet_orbit;
            orbit[planet_orbit]++;

            furthest_orbit = max(furthest_orbit, planet_orbit);
        }
        
        long long total_cost = 0LL;
        for(int i = 1; i <= furthest_orbit; i++)
        {
            if(orbit[i] < c)
                total_cost += orbit[i];
            else
                total_cost += c;
        }

        cout << total_cost << "\n";
    }
}