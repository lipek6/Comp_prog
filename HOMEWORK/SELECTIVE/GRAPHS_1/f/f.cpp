#include<bits/stdc++.h>
using namespace std;

int dir_row[40] = {-1, +1, +0, +0}; // Up, Down, Left, Right
int dir_col[40] = {+0, +0, -1, +1}; // Up, Down, Left, Right

int n, m; 
vector<vector<char>> matrix;

struct coordinate
{
    int x;
    int y;
    coordinate (int x_position, int y_position) : x(x_position), y(y_position) {} 
};


// Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    matrix.resize(n, vector<char>(m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char point; cin >> point;
            matrix[i][j] = point;

            if(point == 'A')
            {
                A.x = j;
                A.y = i;
            }
        }
    }



}