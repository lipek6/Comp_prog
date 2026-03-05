#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        vector<int> month(n);
        vector<long long> psum((2 * n) + 1); psum[0] = 0;       //Double the size to handle cases of travels where the year turns
        for(int i = 0; i < n; i++) 
        {
            cin >> month[i];
            psum[i+1] = psum[i] + month[i]; 
        }
        for(int i = n; i < 2*n; i++)
        {
            psum[i+1] = psum[i] + month[i - n]; 
        }

        while(m--)
        {
            long long visa;
            int arrive_day, arrive_month, depart_day, depart_month;
            cin >> arrive_day >> arrive_month >> depart_day >> depart_month;

            long long year_day_arrive = psum[arrive_month-1] + arrive_day; // To check if the year is turning
            long long year_day_depart = psum[depart_month-1] + depart_day; // To check if the year is turning
             
            if(year_day_arrive > year_day_depart)    // Year turning
            {
                year_day_depart = psum[depart_month - 1 + n] + depart_day;  // Using the second year part of psum
            }
            
            visa = year_day_depart - year_day_arrive  + 1;

            cout << visa << endl;
        }
    }
}