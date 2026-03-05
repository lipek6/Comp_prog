#include<bits/stdc++.h>
using namespace std;

int dir_row[] = {+1, +0, -1, +0}; // down, right, up, left
int dir_col[] = {+0, +1, +0, -1}; // down, right, up, left
int roomsCnt = 0;

void flood_fill(vector<string>& grid, int n, int m, int row, int col);

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++)
    {
        cin >> grid[i]; 
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '.')
            {
                roomsCnt++;
                flood_fill(grid, n, m, i, j); 
            }
        }
    }
    cout << roomsCnt << "\n";
}

void flood_fill(vector<string>& grid, int n, int m, int row, int col)
{
    if(row < 0 || row >= n) return;    // Out of bounds 
    if(col < 0 || col >= m) return;    // Out of bounds 

    if(grid[row][col] != '.') return;  // Is wall?

    grid[row][col] = 'X';
    for(int dir = 0; dir < 4; dir++)
        flood_fill(grid, n, m, row + dir_row[dir], col + dir_col[dir]);
}
