#include<bits/stdc++.h>
#define UNVISITED 1e9
using namespace std;

int dir_row[4] = {-1, +1, +0, +0}; // Up, Down, Left, Right
int dir_col[4] = {+0, +0, -1, +1}; // Up, Down, Left, Right

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, qc; cin >> n >> qc;
    
    vector<vector<char>> forest(n, vector<char>(n));
    vector<pair<int,int>> exits;
    int sps = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> forest[i][j];
            
            if(forest[i][j] == 'E')
                exits.push_back({i,j});
            else if(forest[i][j] == '.')
                sps++;
        }
    }
    
    vector<vector<int>> dist(n, vector<int>(n, UNVISITED));
    queue<pair<int,int>> q;

    for(auto& exit : exits)
    {
        q.push(exit);
        dist[exit.first][exit.second] = 0;
    }

    vector<int> distances(1000, 0);
    while(!q.empty())
    {
        auto& [cur_row, cur_col] = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int new_row = cur_row + dir_row[dir];
            int new_col = cur_col + dir_col[dir];

            if(new_row >= n || new_row < 0) continue;
            if(new_col >= n || new_col < 0) continue;
        
            if(forest[new_row][new_col] == '#') continue;
            if(dist[new_row][new_col] != UNVISITED) continue;

            dist[new_row][new_col] = dist[cur_row][cur_col] + 1;
            distances[dist[new_row][new_col]]++;

            q.push({new_row, new_col});
        }
    }

    distances[0] = 0;
    vector<long long> xbreads(1000, 0);

    for(int i = 1; i <= n; i++)
    {
        xbreads[i] = distances[i-1] + xbreads[i-1];
    }
        
    while(qc--)
    {
        int bread; cin >> bread;
        int valid;

        if(bread >= n)
            valid = xbreads[n];
        else
            valid = xbreads[bread];

        double result = (double)valid/(double)sps;
        cout << setprecision(8) << result << "\n"; 
        
    }
}
