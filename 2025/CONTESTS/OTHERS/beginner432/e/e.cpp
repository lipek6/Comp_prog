#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<int> a(n);
    vector<int> sorted_a(n);
    long long sum = 0;
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        sorted_a[i] = a[i];
    }

    sort(sorted_a.begin(), sorted_a.end());

    while(q--)
    {
        int cmd; cin >> cmd;

        if(cmd == 1)
        {
            int x, y; cin >> x >> y;
            sum -= a[x-1];
            a[x-1] = y;
            sum += y;

            int l = 0, r = n - 1;
            while(l <= r)
            {
                int m = l + (r - l) / 2;
                
                if(sorted_a[m] < y)
                {
                    l = m + 1;
                }
                else if(sorted_a[m] > y)
                {
                    r = m - 1;
                }
                else
                {
                    sorted_a[m] = y;
                    sort(sorted_a.begin(), sorted_a.end());
                    break;
                }
            }
        }


        if(cmd == 2)
        {
            int l, r; cin >> l >> r;

            int j = 0;
            long long value = sum;
            
            while(l > min(sorted_a[j], r) && j < n)
            {
                value = (value + l) - sorted_a[j];
                j++;
            }

            cout << value << "\n";
        }
    }
}