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

    long long num = stoi(number_str);
    long long car = letter - 'a';

    long long pos = num + car;

    long long num_s =  0;
    long long car_s = 'e' - 'a';

    long long pos_s = num_s + car_s;

    long long i = 1;
    long long to_sum = 3;
    
    long long l = 0;
    long long r = 1e18;

    while(l <= r)
    {
        long long m = l + (r-l)/2;

        if(m / (3*))
    
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