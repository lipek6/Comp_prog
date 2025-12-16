#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--)
    {
        int n; cin >> n;
        vector<pair<int,int>> student(n);
        
        for(int i = 0; i < n; i++) cin >> student[i].first >> student[i].second;
        sort(student.begin(), student.end());

        queue<int> q;
        vector<int> answer;
        int time = student[0].first;

        for(int i = 1; i < n; i++)
        {
            student[i].first
            if(q.empty()) answer.push_back(time);
            
        }
    }





}

/*
    There is a QUEUE, ith student goes to the end at l_ith second.
    If more then one comes at the l_ith second, lower index gets the goods.
    If queue.empty(): Use teapot for 1 second and leave;
    If at r_ith second he is not on the front of the queue: Leave;
    Print(When each student gets tea)






*/
