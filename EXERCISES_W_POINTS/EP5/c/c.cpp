#include<bits/stdc++.h>
using namespace std;

int n, k, xi;       // size and amount of subarrays

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    vector<int> best(k);

    int sub_size = n / k;
    vector<int> x(n);
    
    for(int i = 0; i < n; i++)
    {
        cin >> xi;
        x[i] = xi;
    }
    int fact_n = 1;
    for(int i = 1; i < n + 1; i++)
    {
        fact_n = fact_n * i;
    }
    
    vector<vector<int>> sums(fact_n, vector<int>(k, 0));
    for(int i = 0; i < fact_n; i++)    
    {
        int j = 0;
        int sub = 0;

        while(true)
        {
            if(j == sub_size) sub++;

            sums[i][sub] += x[j];
            j++;   

            if(j == n) break;
        }

        int sub_max = 0;
        for(int k = 0; k < n; k++)
        {
            if (sub_max < sums[i][k]) sub_max = sums[i][k];
        }

        next_permutation(x.begin(), x.end());
        int b = 0;
        for(int l = 0; l < n; l++)
        {
            if (best[l] < sums[i][l]) b++;
        }
        if(b >= k)
        {
            best = sums[i];
        }
    }
}