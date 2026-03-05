#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        string sheet; cin >> sheet;
        
        int corrects = 0;

        vector<int> q_amount = {n, n, n, n};
        vector<int> q_count (4, 0);
        
        for(int i = 0; i < 4*n; i++)
        {
            if(sheet[i] == 'A') q_count[0]++;
            if(sheet[i] == 'B') q_count[1]++;
            if(sheet[i] == 'C') q_count[2]++;
            if(sheet[i] == 'D') q_count[3]++;
        }

        for(int i = 0; i < 4; i++)
        {
            if(q_count[i] >= q_amount[i]) corrects += q_amount[i];
            else corrects += q_count[i];
        }
        cout << corrects << "\n";
    }
}