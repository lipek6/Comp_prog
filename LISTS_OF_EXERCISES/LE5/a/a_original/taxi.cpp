#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;                      // Amount of groups of schoolchildren
    int si;
    cin >> n;

    map<int, int> s;           // Groups of schoolchildren
    for(int i = 0; i < n; i++) 
    {
        cin >> si;
        s[si]++;
    }
    
    
    int car_count = 0;
    int i = 0;    
    while(i < n)
    {
        if (s[4] > 0) 
        {
            s[4]--;
            i++;
        }
        else if (s[3] > 0)
        {
            s[3]--;
            i++;
            if (s[1] > 0)
            {
                s[1]--;
                i++;
            }
        }
        else if (s[2] > 0)
        {
            s[2]--;
            i++;
            if(s[2] > 0)
            {
                s[2]--;
                i++;
            }
            else if(s[1] > 0)
            {
                s[1]--;
                i++;
                if(s[1] > 0)
                {
                    s[1]--;
                    i++;
                }
            }
        }
        else if (s[1] > 0)
        {
            s[1]--;
            i++;
            if(s[1] > 0)
            {
                s[1]--;
                i++;
                if(s[1] > 0)
                {
                    s[1]--;
                    i++;
                    if(s[1] > 0)
                    {
                        s[1]--;
                        i++;
                    }
                }
            }
        }
        car_count++; 
    }
    cout << car_count << "\n";
}