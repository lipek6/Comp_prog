#include <bits/stdc++.h>
using namespace std;

int main (void)
{
    int n, h, entry, j, k;

    cin >> n >> h;
    vector<int> up(n);
    vector<int> dw(n);
    j = 0;
    k = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> entry;
        if(i % 2 == 0)
        {
            dw[j] = entry;
            j++;
        }
        else
        {
            up[k] = entry;
            k++;
        }
    }
    sort(up.begin(), up.end());
    sort(dw.begin(), dw.end());
    map<int, int> occurrences;

    for (int i = 1; i <= h; i++)
    {
        int count_up
        int count_dw
    }

}