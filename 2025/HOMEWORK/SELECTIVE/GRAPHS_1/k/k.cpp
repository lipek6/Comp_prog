#include<bits/stdc++.h>
using namespace std;

vector<string> maze;

int n, m;
int dir_row[4] = {-1, +1, +0, +0};
int dir_col[4] = {+0, +0, -1, +1};

void block(int i, int j)
{
    for(int dir = 0; dir < 4; dir++)
    {
        int new_row = i + dir_row[dir];
        int new_col = j + dir_col[dir];

        if(new_row < 0 || new_row >= n) continue;
        if(new_col < 0 || new_col >= m) continue;

        if(maze[new_row][new_col] == '.') maze[new_row][new_col] = '#';
    }
    return;
}

vector<vector<bool>>visited;

bool escape(int i, int j)
{
    visited[i][j] = true;
    for(int dir = 0; dir < 4; dir++)
    {
        int new_row = i + dir_row[dir];
        int new_col = j + dir_col[dir];
        
        if(new_row < 0 || new_row >= n) continue;
        if(new_col < 0 || new_col >= m) continue;
        if(visited[new_row][new_col])   continue;        

        if(maze[new_row][new_col] != '#') escape(new_row, new_col);
    }
    return false;
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--)
    {
        cin >> n >> m;

        maze.clear(); maze.resize(n);
        
        for(int i = 0; i < n; i++) cin >> maze[i];
        
        
        int bad_guys  = 0;
        int good_guys = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(maze[i][j] == 'B') block(i, j), bad_guys++;
                if(maze[i][j] == 'G') good_guys++;
            }
        }

        if(good_guys == 0 && maze[n-1][m-1] != 'B')
        {
            cout << "Yes" << "\n";
            continue;
        }
        if(maze[n-1][m-1] == 'B')
        {
            cout << "No" << "\n";
            continue;
        }


        visited.assign(n, vector<bool>(m, false));        
        escape(n-1, m-1);
        
        string answer = "Yes";
        
        for(int i = 0; i < n; i++)
        {
            if(answer == "No") break;
            for(int j = 0; j < m; j++)
            {
                if(maze[i][j] == 'B' && visited[i][j] == true)
                {
                    answer = "No";
                    break;
                }
                else if(maze[i][j] == 'G' && visited[i][j] == false)
                {
                    answer = "No";
                    break;
                }
            }
        }

        cout << answer << "\n";
    }
}