#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    while(true)
    {
        int n; cin >> n;

        if(n == 0) return 0;
        
        string bits;
        int bit_sum = 0;
        int remaining;
        int quocient = n;

        while(quocient != 0 && quocient != 1)
        {
            remaining = quocient % 2;
            if(remaining == 0) bits.append("0");
            if(remaining == 1) bits.append("1");
            bit_sum += remaining;
            quocient = quocient / 2;
        }
        
        if(quocient == 0) bits.append("0");         
        if(quocient == 1) bits.append("1");         
        bit_sum += quocient;
        
        string bits_corrected;
        for(int i = bits.size() - 1; i >= 0; i--)
        {
            bits_corrected += bits[i];
        }

        cout << "The parity of " << bits_corrected <<" is " << bit_sum << " (mod 2).\n";
    }
}