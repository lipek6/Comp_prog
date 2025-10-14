#include<bits/stdc++.h>

int total = 0;
int wi;

int main(void)
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    // A person is unhappy if their wealth is strictly less than half of the average wealth
    // If strictly more than half of the total population nn are unhappy, Robin Hood will appear by popular demand


    int t, n;        // Test cases, total population
    
    
    cin >> t;
    while(t--)
    {
        int max = 0;   // Richest person, addres, value
        total = 0;
        
        cin >> n;
        vector<int> w(n);
        
        for(int i = 0; i < n; i++)
        {
            cin >> wi;
            total += wi;
            if(max < wi) max = wi;
            w[i] = wi;
        }

        float avg = total / n; 
        int hw_count = 0;
        int mid = 99999999;
        sort(w.begin(), w.end());

        for(int i = 0; i < n; i++)
        {
            if(w[i] < avg)
            {
                hw_count++;
            }
            else if (i >= n/2)
            {
                mid = w[i];
                break;
            }
        }

        if(hw_count > n/2)
        {
            cout << "0" << "\n" ;
            continue;
        }
        
        int i = 0;
        while(avg/2 < mid)
        {
            avg = (total + i) / n;
            i++;
        }
        cout << i << "\n" ;
    }
}