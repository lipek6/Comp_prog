#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<bool> teeth(1001, false);
    vector<int> t(q);

    for(int i = 1; i <= n; i++) teeth[i] = true;

    for(int i = 0; i < q; i++)
    {
        int target; cin >> target;

        if(teeth[target] == false)
            teeth[target] = true;
        else
            teeth[target] = false;
    }

    int amount_teeths = 0;
    for(int i = 1; i <= n; i++)
    {
        if(teeth[i] == true) 
            amount_teeths++;
    }

    cout << amount_teeths << "\n";
}