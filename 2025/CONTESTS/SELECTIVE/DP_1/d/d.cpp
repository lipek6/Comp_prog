#include<bits/stdc++.h>
#define loop true
#define calc false
using namespace std;

const unsigned long long modular = 1e9 + 7;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<bool, unsigned long long>> ops; unsigned long long total = 0;
    
    for(int i = 0; i < N; i++)
    {
        string cmd; cin >> cmd;
        if(cmd == "for")
        {
            unsigned long long k; cin >> k;
            ops.push_back({loop, k});
        }
        else if(cmd == "calc")
        {
            unsigned long long k; cin >> k;
            ops.push_back({calc, k});
        }
        else if(cmd == "end")
        {
            int j = ops.size() - 1;
            unsigned long long calcs = 0;

            while(ops[j].first != loop)
            {
                calcs += ops[j].second;
                ops.pop_back(); j--;                
            }
            unsigned long long num_ops = ((calcs % modular) * (ops[j].second % modular)) % modular;
            ops.pop_back();
            ops.push_back({calc, num_ops % modular});
        }
    }

    int j = ops.size() - 1;
    while(!ops.empty())
    {
        total += ops[j].second;
        ops.pop_back(); j--;
    }
    
    cout << total % modular << "\n";
}