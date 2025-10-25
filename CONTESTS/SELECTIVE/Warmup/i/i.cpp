#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--)
    {
        string time; cin >> time;

        int big_hour = time[0] - '0';
        int sml_hour = time[1] - '0';
        int hours =  (big_hour * 10) + sml_hour;

        int big_min = time[3] - '0';
        int sml_min = time[4] - '0';
        int mins = (big_min * 10) + sml_min;

        // Now everything is an integer
        string m;
        if(hours >= 12 || (hours == 12) && mins > 1) m = "PM";
        else m = "AM";        
        
        hours = hours % 12;
        
        if(hours == 0) hours = 12;
        
        if(hours < 10) cout << '0' << hours << ':';
        else cout << hours << ':';
        if(mins < 10)  cout << '0' << mins << " " <<  m << endl;
        else cout << mins << " " << m << endl;
    }
}