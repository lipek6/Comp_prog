#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string n; cin >> n;

    vector<int> d(n.size());

    int n_int = -1;
    while (n_int != 0)
    {
        for(int i = 0; i < n.size(); i++)
        {
            d[i] = n[i] - '0';
            n_int += d[i] * pow(10, n.size()-1);
        }
        sort(d.begin(), d.end(), greater());
        
        n = n - d[0];
    }
}