#include<bits/stdc++.h>
using namespace std;

// No reversion here mate
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> q;
    string cmd; 
    bool rev = false;
    deque<int> dq;
    while(q--)
    {
        cin >> cmd;
        
        if(cmd == "back")
        {
            if(dq.empty())
            {
                cout << "No job for Ada?\n";
            }
            else
            {
                if(rev)
                {
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }
                else
                {
                    cout << dq.back() << "\n";
                    dq.pop_back();
                }
            }
        }

        else if(cmd == "front")
        {
            if(dq.empty())
            {
                cout << "No job for Ada?\n";
            }
            else
            {
                if(rev)
                {
                    cout << dq.back() << "\n";
                    dq.pop_back();
                }
                else
                {
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }
            }            
        }

        else if(cmd == "reverse")
        {
            rev = (!rev)? true : false;
        }
        
        else if(cmd == "push_back")
        {
            cin >> n;
            if(rev)
                dq.push_front(n);
            else
                dq.push_back(n);
        }

        else
        {
            cin >> n;
            if(rev)
                dq.push_back(n);
            else
                dq.push_front(n);
        }
    }
}