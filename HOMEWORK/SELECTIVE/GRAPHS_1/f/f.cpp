#include<bits/stdc++.h>
#define UNVISITED -1
using namespace std;

int dir_row[4] = {-1, +1, +0, +0}; // Up, Down, Left, Right
int dir_col[4] = {+0, +0, -1, +1}; // Up, Down, Left, Right

int n, m; 

string str_path;
vector<vector<char>> matrix;
vector<vector<int>>  timed_path;
vector<vector<int>> A_path;

int exit_i = UNVISITED;
int exit_j = UNVISITED;

void escape(int cur_row, int cur_col, int time)
{
    timed_path[cur_row][cur_col] = time;

    for(int dir = 0; dir < 4; dir++)
    {
        int new_row = dir_row[dir] + cur_row;
        int new_col = dir_col[dir] + cur_col;

        if(new_row >= n || new_row < 0) continue;
        if(new_col >= m || new_col < 0) continue;
        if(timed_path[new_row][new_col] != UNVISITED) continue;
        if(matrix[new_row][new_col] !=  '.') continue;
        

        if(matrix[new_row][new_col] ==  '.' && (new_row == n-1 || new_col == m-1))
        {
            timed_path[new_row][new_col] = time + 1;
            
            exit_i = new_row;
            exit_j = new_col;

            return;
        }


        escape(new_row, new_col, time + 1);
    }
}


void reconstruct_path (int cur_row, int cur_col, int time)
{
    for(int dir = 0; dir < 4; dir++)
    {
        int new_row = dir_row[dir] + cur_row;
        int new_col = dir_col[dir] + cur_col;

        if(new_row >= n || new_row < 0) continue;
        if(new_col >= m || new_col < 0) continue;
        if(matrix[new_row][new_col] != '.') continue;        
        
        if(timed_path[new_row][new_col] == time - 1)
        {
            if(dir == 0) str_path += 'D'; // THESE GUYS ARE INVERSED
            if(dir == 1) str_path += 'U';
            if(dir == 2) str_path += 'R';
            if(dir == 3) str_path += 'L';

            A_path[new_row][new_col] = time - 1;
            reconstruct_path (new_row, new_col, time - 1);
        }
    }
}




// Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    matrix.resize(n, vector<char>(m));
    timed_path.assign(n, vector<int>(m, UNVISITED));
    A_path.assign(n, vector<int>(m, UNVISITED));

    int A_i, A_j;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char point; cin >> point;
            matrix[i][j] = point;
            
            if(point == 'A')
            {
                A_i = i;
                A_j = j;
            }
        }
    }

    escape(A_i, A_j, 0);
    
    if(exit_i == -1 || exit_j == -1)
    {
        cout << "NO\n";
        return 0;
    }
    
    A_path[exit_i][exit_j] = timed_path[exit_i][exit_j];

    reconstruct_path(exit_i, exit_j, timed_path[exit_i][exit_j]);
    
    cout << "done\nexit_i = " << exit_i << "\nexit_j = " << exit_j << "\n";

    for(int i = str_path.size() - 1; i >= 0; i--)
    {
        cout << str_path[i];
    }
    cout << "\n";
}