#include<bits/stdc++.h>
using namespace std;

int n, m;

int dir_row[4] = {-1, +1, +0, +0};
int dir_col[4] = {+0, +0, -1, +1};

vector<vector<vector<int>>> VisitedByBadGuys;
vector<vector<vector<int>>> VisitedByGoodGuys;
vector<vector<char>> maze;

void floodfill (bool is_good, int guy, int i, int j)
{
    if(is_good)
        VisitedByGoodGuys[guy][i][j] = 1;
    else                     
        VisitedByBadGuys[guy][i][j]  = 1;
    
    for(int dir = 0; dir < 4; dir++)
    {
        int next_row = i + dir_row[dir];
        int next_col = j + dir_col[dir];
        
        if(next_row < 0 || next_row >= n) continue;
        if(next_col < 0 || next_col >= m) continue;
        if(is_good  && VisitedByGoodGuys[guy][next_row][next_col] == 1) continue;
        if(!is_good && VisitedByBadGuys [guy][next_row][next_col] == 1) continue;

        if(maze[next_row][next_col] != '#') floodfill(is_good, guy, next_row, next_col);
    }
}


// One flood fill for each dude? If we can find somewhere to stop bad dudes and let good dudes pass
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--)
    {
        cin >> n >> m;

        maze.clear();
        maze.resize(n, vector<char>(m));
        
        int bad_guys_counter  = 0;
        int good_guys_counter = 0;
        char current_character;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> current_character;

                maze[i][j] = current_character;

                if(current_character == 'G')
                    good_guys_counter++;
                else if(current_character == 'B')
                    bad_guys_counter++;
            }
        }
        
        VisitedByBadGuys.assign (bad_guys_counter,  vector<vector<int>>(n, vector<int>(m, 0)));
        VisitedByGoodGuys.assign(good_guys_counter, vector<vector<int>>(n, vector<int>(m, 0)));
        
        int flood_good_guy = 0;
        int flood_bad_guy  = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(maze[i][j] == 'G')
                {
                    floodfill(true, flood_good_guy++, i, j);
                }
                else if(maze[i][j] == 'B')
                {
                    floodfill(false, flood_bad_guy++, i, j);
                }
            }
        }
    }
}