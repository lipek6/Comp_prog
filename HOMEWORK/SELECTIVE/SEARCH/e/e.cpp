#include<bits/stdc++.h>
using namespace std;

// Create a prefix sum of the vector ordered by greater looks neat :)
// Maybe I can run a binary search on the prefix sum hihi
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int n, q; cin >> n >> q;                    // Amount of candys and queries
        vector<int> a(n);                           // Sugar of each candy

        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end(), greater());

        vector<long long> presum(n+1); presum[0] = 0;
        for(int i = 0; i < n; i++)
        {
            presum[i+1] = presum[i] + a[i];
        }

        int x;
        for(int i = 0; i < q; i++)
        {
            cin >> x;

            if(x > presum[n])
            {
                cout << "-1" << "\n";
            }
            else
            {
                int l = 1;
                int r = n;
                int m;
                int answer;

                while(l <= r)
                {
                    m = l + (r - l) / 2;
                    
                    if(presum[m] >= x)
                    {
                        answer = m;
                        r = m - 1;
                    }
                    else
                    {
                        l = m + 1;
                    }
                }
                cout << answer << "\n";
            }
        }
    }
}

// PUTA MERDA KKKKKKKKKK, parece que deu certo de primeira, cara, que orgulho da porra.
// E porque têm alguém lendo isso aqui? Pode ler, o pai tá binariamente procurador.