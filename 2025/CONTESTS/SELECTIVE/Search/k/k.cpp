#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x, d; cin >> n >> x >> d;
    vector<long long> s(n);
    vector<long long> g1;
    vector<long long> g2;
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<vector<long long>> groups;
    

    long long g_count = 0;    

    do
    {
        long long gmax = 0;
        long long gmin = 1e9;
        long long sum = 0;

        for(int team_size = 1; team_size <= n; team_size++)
        {
            vector<long long> curr_group;
            for(int i = 0; i < team_size; i++)
            {
                sum += s[i];
                gmax = max(s[i], gmax);
                gmin = min(s[i], gmin);
                curr_group.push_back(s[i]);
            }
            if(gmax - gmin <= d && sum >= x)
            {
                bool failed = false;
                for(int j = 0; j < groups.size(); j++)
                {
                    if(failed) break;
                    if(groups[j].size() == curr_group.size())
                    {
                        for(int k = 0; k < groups[j].size(); k++)
                        {
                            if(groups[j][k] == curr_group[k])
                            {
                                failed = true;
                                break;
                            }
                        }
                    }
                }
                if(!failed)
                {
                    groups.push_back(curr_group);
                    g_count++;
                }

            }
        }
    }
    while(next_permutation(s.begin(), s.end())); // Group permutations

    cout << g_count << "\n";
}