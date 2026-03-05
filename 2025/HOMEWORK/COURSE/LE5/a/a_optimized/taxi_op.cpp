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
    car_count = s[4];
    s[4] = 0;

    car_count += s[3];        
    s[1] = max(0 , s[1] - s[3]);

    car_count += s[2] / 2;
    s[2] = s[2] % 2;        // It is only possible to remain 1 or 0 groups of 2

    if(s[2] == 1)
    {
        car_count++;
        s[1] = max(0, s[1] - 2);
    }

    car_count += (s[1] + 3) / 4;
    cout << car_count << "\n";  
}