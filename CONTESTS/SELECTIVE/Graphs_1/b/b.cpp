#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string c; 
    cin >> c;

    string number_str;
    char letter;
    for(int i = 0; i < c.size(); i++)
    {
        if(c[i] - 48 >= 0 && c[i] - 48 <= 9)
            number_str += c[i];
        else
            letter = c[i];
    }

    //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa use stoll instead of stoi
    unsigned long long int num = stoll(number_str) * (unsigned long long int)26;
    unsigned long long int car = letter - 'a';

    unsigned long long int pos = num + car;

    unsigned long long int pos_s = 4;

    unsigned long long int i = 1;
    unsigned long long int to_sum = 3;
    while(true)
    {
        if(pos_s > pos)
        {
            cout << -1 << "\n";
            return 0;
        }

        if(pos_s == pos)
        {
            cout << i << "\n";
            return 0;
        }

        pos_s += to_sum;
        to_sum += 2;
        i++;
    }
}