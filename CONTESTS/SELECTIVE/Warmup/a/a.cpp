#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        string day; cin >> day;

        map<char, int> tasks;
        tasks['A'] = 0;tasks['B'] = 0;tasks['C'] = 0;tasks['D'] = 0;tasks['E'] = 0;tasks['F'] = 0;tasks['G'] = 0;tasks['H'] = 0;tasks['I'] = 0;tasks['J'] = 0;tasks['K'] = 0;tasks['L'] = 0;tasks['M'] = 0;tasks['N'] = 0;tasks['O'] = 0;tasks['P'] = 0;tasks['Q'] = 0;tasks['R'] = 0;tasks['S'] = 0;tasks['T'] = 0;tasks['U'] = 0;tasks['V'] = 0;tasks['W'] = 0;tasks['X'] = 0;tasks['Y'] = 0;tasks['Z'] = 0;

        int i = 1;
        while(true)
        {
            while(day[i] == day[i - 1])
            {
                i++;
                continue;
            }
            if(tasks[day[i]] == 1)
            {
                cout << "NO" << endl;
                break;
            }
            else
            {
                tasks[day[i - 1]] = 1;      // 1 means done
                i++;
            }
            if(i >= n)
            {
                cout << "YES" << endl;
                break;
            }
                
        }


    }
}