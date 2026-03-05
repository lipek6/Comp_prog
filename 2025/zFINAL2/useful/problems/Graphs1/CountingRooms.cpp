#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<string> matrix;

// We will use the directions array to simplify our life
int dir_row[] = {1, 0, -1, 0};    // S, E, N, W
int dir_col[] = {0, 1, 0, -1};    // S, E, N, W

// Classic flood fill problem, but we have walls and rooms
void floodfill(int row, int col)
{
    if(row < 0 || row >= n) return;    // Out of bounds checking
    if(col < 0 || col >= m) return;    // Out of bounds checking

    if(matrix[row][col] != '.') return;       // Land checking

    matrix[row][col] = 'X';
    for(int dir = 0; dir < 4; dir++)
    {
        floodfill(row + dir_row[dir], col + dir_col[dir]);
    }
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    int rooms = 0;
    matrix.resize(n);
    for(int i = 0; i < n; i++) cin >> matrix[i];

    for(int i = 0; i < n; i++)      // Rows
    {
        for(int j = 0; j < m; j++)  // Collums
        {
            if(matrix[i][j] == '.')
            {
                rooms++;
                floodfill(i, j);   // We will fill the connected dots (the room) with any shit to avoid counting a room more than one time
            }
        }
    }
    cout << rooms << "\n";
}