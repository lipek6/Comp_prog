#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string str; cin >> str;
    
    char current_element = str[0];
    int max_length = 1;
    int current_length = 1;
    for(int i = 1; i < n; i++)
    {
        if(current_element == str[i])
            current_length++;
        else
        {
            current_element = str[i];
            current_length = 1;
        }
        max_length = max(current_length, max_length);
    }
    cout << max_length << "\n";
}