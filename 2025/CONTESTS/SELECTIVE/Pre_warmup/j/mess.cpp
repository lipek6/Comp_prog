#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, f, a, b, t; cin >> t;

    while(t--)
    {
        cin >> n >> f >> a >> b;
        vector<long long> m(n + 1);
        m[0] = 0;
        for(int i = 1; i < n + 1; i++) cin >> m[i];
        
        for(int i = 0; i < n; i++)
        {
            long long wait_cons = (m[i + 1] - m[i]) * a;
            long long turn_cons = b;
     
            if(wait_cons < turn_cons)
                f -= wait_cons;
            else 
                f -= turn_cons;
        }

        if(f > 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}