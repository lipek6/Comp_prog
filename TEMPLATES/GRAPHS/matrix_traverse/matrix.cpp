#include<bits/stdc++.h>
using namespace std;
#define UNVISITED -1
enum {NORTH = 0, SOUTH = 1, WEST = 2, EAST = 3};

int dir_row[4] = {-1, +1, +0, +0};
int dir_col[4] = {+0, +0, -1, +1};


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nrows, ncols, start_row, start_col; start_row = 0;
    
    while(true)
    {
        cin >> nrows >> ncols >> start_col;
        if(nrows == 0 && ncols == 0 && start_col == 0) break;

        start_col--;    // Index correction

        vector<string> matrix(nrows);
        vector<vector<int>> visited_matrix(nrows, vector<int>(ncols, UNVISITED));

        for(int i = 0; i < nrows; i++) cin >> matrix[i];

        int row_pos = 0;
        int col_pos = start_col;
        
        int steps = 0;
        int looped_steps = 0;

        bool is_inside = (row_pos < nrows && row_pos >= 0) && (col_pos < ncols && col_pos >= 0);

        while(is_inside)
        {
            visited_matrix[row_pos][col_pos] = steps;

            char instruction = matrix[row_pos][col_pos];
            
            if(instruction == 'N')
            {
                row_pos += dir_row[NORTH];
                col_pos += dir_col[NORTH];
            }

            else if(instruction == 'S')
            {
                row_pos += dir_row[SOUTH];
                col_pos += dir_col[SOUTH];
            }

            else if(instruction == 'W')
            {
                row_pos += dir_row[WEST];
                col_pos += dir_col[WEST];
            }

            else if(instruction == 'E')
            {
                row_pos += dir_row[EAST];
                col_pos += dir_col[EAST];
            }

            is_inside = (row_pos < nrows && row_pos >= 0) && (col_pos < ncols && col_pos >= 0);
            steps++;
            
            if(is_inside && visited_matrix[row_pos][col_pos] != UNVISITED)
            {
                int WhenLoopStarts = visited_matrix[row_pos][col_pos];
                looped_steps = steps - WhenLoopStarts;
                steps = steps - looped_steps;
                break; 
            }
        }

        if(looped_steps == 0)
            cout << steps << " step(s) to exit\n";
        else
            cout << steps << " step(s) before a loop of " << looped_steps << " step(s)\n";
    }
}