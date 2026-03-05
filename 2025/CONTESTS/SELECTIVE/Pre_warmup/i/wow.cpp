#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    
    string s; cin >> s;

    vector<int> o_locations;
    o_locations.push_back(-1);
    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'o')
        {
            o_locations.push_back(i);
        }
    }
    o_locations.push_back(s.length());

    int wow = 0;
    for(int i = 1; i < o_locations.size() - 1; i++)
    {
        int l = (o_locations[i] - o_locations[i - 1] - 1) / 2;
        int r = (o_locations[i + 1] - o_locations[i] - 1) / 2;
        
            wow += (l*r)/2;
    }
    cout << wow << "\n";
}