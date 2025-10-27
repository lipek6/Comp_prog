#include<bits/stdc++.h>
using namespace std;

// This one is about stacks I think
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    stack<int> a;
    stack<int> b;
    stack<int> c;
    for(int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        a.push(ai);
    }
    b.push(0);
    c.push(0);

    vector<string> actions;
    int q = 0;

    while(!a.empty() || b.top() != 0)
    {
        if(a.empty() && b.top() != c.top() + 1)
        {
            cout << "-1" << "\n";
            return 0;
        }

        if(!a.empty() && c.top() + 1 == a.top())
        {
            c.push(a.top());
            a.pop();
            actions.push_back("A C");
            q++;
        }
        else if(c.top() + 1 == b.top())
        {
            c.push(b.top());
            b.pop();
            actions.push_back("B C");
            q++;
        }
        else
        {
            b.push(a.top());
            a.pop();
            actions.push_back("A B");
            q++;
        }
    }
    cout << q << "\n";
    for(int i = 0; i < actions.size(); i++)
    {
        cout << actions[i] << "\n";
    }
}