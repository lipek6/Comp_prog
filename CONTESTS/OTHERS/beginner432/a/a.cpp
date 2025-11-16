#include<bits/stdc++.h>
using namespace std;

//The color of cell (x,y) is black if 0≤x≤X−1 and 0≤y≤Y−1, and white otherwise.
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c; cin >> a >> b >> c;

    int digit_1 = max(a, max(b, c));
    int digit_2;
    int digit_3 = min(a, min(b, c));


    if      (digit_1 == a && digit_3 == b)  digit_2 = c;
    else if (digit_1 == b && digit_3 == a)  digit_2 = c;
    else if (digit_1 == b && digit_3 == c)  digit_2 = a;
    else if (digit_1 == c && digit_3 == b)  digit_2 = a;
    else if (digit_1 == a && digit_3 == c)  digit_2 = b;
    else if (digit_1 == c && digit_3 == a)  digit_2 = b;
    
    cout << digit_1 << digit_2 << digit_3 << "\n";

}