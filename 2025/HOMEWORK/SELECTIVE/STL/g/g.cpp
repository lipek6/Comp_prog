#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, t, q; cin >> n >> t >> q;    // Number of students, days of scheduling and queries

    set<int> students;                           
    for(int i = 1; i <= n; i++) students.insert(i);
    
    vector<vector<int>> dpx(q, vector<int>(3));

    // I fucking forgot that dictionaries existed when doing this, now I need to unshit this
    map<int, vector<int>> outers;   // When and who got out that day 
    map<int, vector<int>> inners;   // When and who got in that day

    for(int i = 0; i < q; i++)
    {
        cin >> dpx[i][0] >> dpx[i][1] >> dpx[i][2];             // On day 'd', student 'p' cannot pull duty for the next 'x' days
        
        outers[dpx[i][0]].push_back(dpx[i][1]);
        
        if(dpx[i][0] + dpx[i][2] <= t)  // Checking validity
            inners[dpx[i][0] + dpx[i][2]].push_back(dpx[i][1]);
    }

    //sort(inners.begin(), inners.end());
    //sort(outers.begin(), outers.end());

    int j = 1;  // Pointer to the current student on schedule
    for(int i = 1; i <= t; i++)
    {
        // Guys who came back today
        if(inners.count(i)) // Count checks if there is something on this day
        {
            for(int guy = 0; guy < inners[i].size(); guy++) students.insert(inners[i][guy]);
        }
        // Guys who will be out today
        if(outers.count(i))
        {
            for(int guy = 0; guy < outers[i].size(); guy++) students.erase(outers[i][guy]);
        }

        if(students.empty())
        {
            cout << "-1" << " ";
            j = 1;
        }
        else
        {
            int the_guy = *students.lower_bound(j);
            //I wanna the first idx student and check if the student is there
            if(!students.count(the_guy))
            {
                the_guy = *students.begin();
                j = 1;
            }
            cout << the_guy << " ";
            j = (the_guy % n) + 1;  // Making it works on module n (so we can rotate the list)
        }
    }
    cout << "\n";
}