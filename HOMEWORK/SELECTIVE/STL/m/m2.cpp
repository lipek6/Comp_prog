#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> x(n);

    priority_queue<int, vector<int>, greater<int>> up; // Heap (min) my beloved 1
    priority_queue<int>                            dw; // Heap (max) my beloved 2
    
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];

        if(i > k - 1)
        {
            dw.push()



        }
    }

}