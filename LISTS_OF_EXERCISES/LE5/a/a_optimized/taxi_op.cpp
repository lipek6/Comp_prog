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
    
    
    int car_count = s[4];
    s[4] = 0;

    int groups_3_1 = min(s[3], s[1]);
    car_count += groups_3_1;
    s[3] -= groups_3_1;
    s[1] -= groups_3_1;

    int groups_2_2 = s[2] / 2;
    car_count += groups_2_2;
    s[2] -= groups_2_2 * 2;

    int groups_2_1_1 = min(s[2], s[1] / 2);
    car_count += groups_2_1_1;
    s[2] -= groups_2_1_1;
    s[1] -= groups_2_1_1; 
    
    int groups_1_1_1_1 = s[1] / 4;
    car_count += groups_1_1_1_1;
    s[1] -= groups_1_1_1_1;

    car_count += s[1] + s[2] + s[3] + s[4];

    cout << car_count << "\n";
}