#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> candidates(n + 1, 0);
    
    int vote_to;
    int winner_votes = 0;
    int winner = 1;

    for(int i = 0; i < m; i++)
    {
        cin >> vote_to;
        candidates[vote_to]++;

        if(candidates[vote_to] > winner_votes || candidates[vote_to] == winner_votes && vote_to < winner)
        {
            winner_votes = candidates[vote_to];
            winner = vote_to;
        }
        cout << winner << "\n";
    }

}