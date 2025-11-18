#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    string c;
    string x;
    while(getline(cin, c) && getline(cin, x))
    {
        vector<int> c_int;
        vector<int> x_int;

        for(int i = 0; i < c.size(); i++)
        {
            string number; c_int >> number;
            c_int.push_back(stoi(number));
        }

        for(int i = 0; i <= x.size(); i++)
        {
            string number; x_int >> number;
            x_int.push_back(stoi(number));
        }
    
        for(int i = 0; i < x_int.size(); i++)
        {
            long long result = 0LL;
            
            for(int j = 0; j < c_int.size(); j++)            
            {
                result += c_int[j] * pow(x_int[i], c_int.size() - 1 - j);
            }

            cout << result << " ";
        }
        cout << "\n";
    }
}