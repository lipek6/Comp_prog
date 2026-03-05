#include<bits/stdc++.h>
using namespace std;

long long n = 0;

void find_pattern(string str, int sub_size)
{
    if(sub_size == 0) return;

    int str_size = str.size();
    int str_end  = str.size()-1;

    vector<string> elements;
    
    for(int i = 0; i <= str_end; i += sub_size)
    {
        elements.push_back(str.substr(i, i+sub_size));
    }

    string first_sub = elements[0];
    for(string sub_string : elements)
    {
        if(first_sub != sub_string)
        {
            find_pattern(str, sub_size-1);
            return;
        }
    }

    find_pattern(str, sub_size-1);
    n = sub_size / elements.size();
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    while(true)
    {
        cin >> str; if(str == ".") break;
        
        find_pattern(str, str.size() / 2);

        cout << n << "\n";
        break;
    }
}