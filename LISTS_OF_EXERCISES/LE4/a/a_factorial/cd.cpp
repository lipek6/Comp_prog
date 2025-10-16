#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;        // Size of the tape in minutes
    int t_count;  // Amount of tracks

    while(cin >> n)
    {
        cin >> t_count;

        int t_fact = 1;
        for(int i = 1; i < t_count + 1; i++)        
        {
            t_fact = t_fact * i;
        }

        vector<int> t(t_count); 
        vector<int> t_og(t_count); 
        vector<int> t_max(t_count); 
        for(int i = 0; i < t_count; i++) 
        {
            cin >> t[i];
            t_og[i] = t[i];
        }

        int max_sum   = 0;
        int max_tapes = 0;
        
        for (int i = 0; i < t_fact; i++)
        {
            int sum = 0;
            int j   = 0;
            for (; j < t_count; j++)
            {
                if(sum + t[j] <= n) sum += t[j];
                else break;
            }

            if((n - sum) <= (n - max_sum))      // If we filled more than max_sum (i.e. we are closer to n), max is now the new max found in the loop
            {
                max_tapes = j;           
                max_sum   = sum;
                copy(t.begin(), t.begin() + j, t_max.begin());
            }
            
            if(n - sum == 0) break;
            next_permutation(t.begin(), t.end());
        }
        for (int i = 0; i < t_count; i++)
        {   
            for(int j = 0; j < max_tapes; j++)
            {
                if(t_og[i] == t_max[j]) cout << t_og[i] << " ";
            }
        }
        cout << "sum:" << max_sum << endl;
    }
}