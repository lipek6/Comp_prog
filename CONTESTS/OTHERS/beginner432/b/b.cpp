#include<bits/stdc++.h>
using namespace std;

//The color of cell (x,y) is black if 0≤x≤X−1 and 0≤y≤Y−1, and white otherwise.
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string entry; cin >> entry;
    int a = entry[0] - '0';
    int b = entry[1] - '0';
    int c = entry[2] - '0';

    int digit_1 = min(a, min(b, c));
    int digit_2;
    int digit_3 = max(a, max(b, c));


    if      (digit_1 == a && digit_3 == b)  digit_2 = c;
    else if (digit_1 == b && digit_3 == a)  digit_2 = c;
    else if (digit_1 == b && digit_3 == c)  digit_2 = a;
    else if (digit_1 == c && digit_3 == b)  digit_2 = a;
    else if (digit_1 == a && digit_3 == c)  digit_2 = b;
    else if (digit_1 == c && digit_3 == a)  digit_2 = b;

    if(digit_1 == 0)
    {
        cout << digit_2 << digit_1 << digit_3 << "\n";
        return 0;
    }
    else
    {
        cout << digit_1 << digit_2 << digit_3 << "\n";
        return 0;
    }
}