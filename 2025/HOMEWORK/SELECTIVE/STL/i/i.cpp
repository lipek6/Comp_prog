#include<bits/stdc++.h>
using namespace std;

// I NEED TO CHECK ALLLLL THE FUCKING POSSIBLE PAIRS OF HIM GETTING TO THE MOVIES AND GETTING OUT OF THE MOVIES
// Maybe, I don't give a fuck do the middle ones where 
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;

    while(tc--)
    {
        int n, m; cin >> n >> m;   
        
        vector<long long> psum(n+1);             
        vector<pair<int,int>> lr(n);
        vector<vector<int>>matrix()                       
        for(int i = 0; i < n; i++)
        {
            cin >> lr[i].first >> lr[i].second;
            
            psum[i+1] = psum[i] + x;
        }
        
        sort(lr.begin(), lr.end());

        int j = 0;
        for(int i = 1; i <= m; i++)
        {
            while(i <= lr[j].first && i >= lr[j].second)
            {

            }
        }











    }


}