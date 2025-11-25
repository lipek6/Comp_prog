#include<bits/stdc++.h>
using namespace std;
const long long modular = 1e9 + 7;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long fact_n = 1;
    for(int i = 1; i < 1e6 + 1; i++)
    {
        fact_n = ((fact_n % modular) * (i % modular)) % modular;
        cout << "factorials[" << i << "] = " << fact_n << ";\n";
    }

}