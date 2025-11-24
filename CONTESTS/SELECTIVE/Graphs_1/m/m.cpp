#include<bits/stdc++.h>
#define UNVISITED -1
using namespace std;

int amount = 0;
int dir_row[] = {1, 1, 0, -1, -1, -1, 0, 1};    // S, SE, E, NE, N, NW, W, SW
int dir_col[] = {0, 1, 1, 1, 0, -1, -1, -1};    // S, SE, E, NE, N, NW, W, SW
int letters[] = {'U', 'V', 'A'};

void dfs(vector<vector<char>>& matrix, int& n, int& m, int row, int col, int og_dir)
{
    char curr_letter = toupper(matrix[row][col]);

    if(curr_letter == 'U')
    {
        for(int dir = 0; dir < 8; dir++)
        {
            int new_row = dir_row[dir] + row;
            int new_col = dir_col[dir] + col;

            if(new_row < 0 || new_row >= m) continue;    // Out of bounds checking
            if(new_col < 0 || new_col >= n) continue;    // Out of bounds checking    

            char next_letter = toupper(matrix[new_row][new_col]);   

            if(next_letter != 'V') continue;
            dfs(matrix, n, m, new_row, new_col, dir);            
        }
    }

    if(curr_letter == 'V')
    {
        int new_row = dir_row[og_dir] + row;
        int new_col = dir_col[og_dir] + col;

        if(new_row < 0 || new_row >= m) return;    // Out of bounds checking
        if(new_col < 0 || new_col >= n) return;    // Out of bounds checking   

        char next_letter = toupper(matrix[new_row][new_col]);   
        if(next_letter == 'A') amount++;
        return;
    }
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;

    vector<pair<int,int>> sources;
    vector<vector<char>> matrix (m, vector<char>(n));
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            cin >> matrix[i][j];
            if(toupper(matrix[i][j]) == 'U') sources.push_back({i, j});
        }
    }

    for(auto &[i, j] : sources)
    {
        dfs(matrix, n, m, i, j, 0);
    }
    cout << amount << "\n";
}


