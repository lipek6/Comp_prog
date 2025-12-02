#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned long long  total_cost = 0ULL;
    
    int s_len, t_len, insert_cost, remove_cost, modify_cost;
    cin >> s_len >> t_len >> insert_cost >> remove_cost >> modify_cost;

    string s; cin >> s;     // Turn normal into strange;
    string t; cin >> t;

    int length = max(s_len, t_len);

    for(int i = 0; i < length; i++)
    {
        if(s[i] == t[i]) continue;
        


    }
}