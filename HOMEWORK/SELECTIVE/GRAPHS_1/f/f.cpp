#include<bits/stdc++.h>
#define UNVISITED -1
using namespace std;

int dir_row[4] = {-1, +1, +0, +0}; // Up, Down, Left, Right
int dir_col[4] = {+0, +0, -1, +1}; // Up, Down, Left, Right

int n, m; 

vector<vector<char>> matrix;
vector<vector<int>>  timed_path;

vector<vector<int>> escape(int cur_row, int cur_col, int time, vector<vector<int>> path)
{
    path.assign(n, vector<int>(m, UNVISITED));

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
            cout << "FOUND\n";
            
            path[new_row][new_col] = time + 1;

            return path;
        } 
        
        path[new_row][new_col] = time + 1;
        
        escape(new_row, new_col, time + 1, path);

        path[new_row][new_col] = UNVISITED;
    }
    return path;
}




// Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    matrix.resize(n, vector<char>(m));
    timed_path.assign(n, vector<int>(m, UNVISITED));

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

    vector<vector<int>> path;
    path = escape(A_i, A_j, 0, path);
    cout << "done\n";
}