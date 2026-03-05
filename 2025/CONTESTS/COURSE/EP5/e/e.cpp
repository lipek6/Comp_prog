#include<bits/stdc++.h>
using namespace std;

// It was dp and I though it was greedy :(
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    

    int steps = 0;
    while(a != b)
    {

        int big_size = max(a,b);
        int cut = ceil(big_size / 2)
        int left = big_size - cut;
        int rigth = cut;
    }
 

}
