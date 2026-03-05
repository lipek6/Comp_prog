#include<bits/stdc++.h>
#define GRID_SIZE 20
#define NOTHING 0
#define BLACK 1
#define WHITE 2
using namespace std;

int dir_row[4] = {-1, +1, +0, +0}; // Up, Down, Left, Right
int dir_col[4] = {+0, +0, -1, +1}; // Up, Down, Left, Right


vector<vector<int>> grid(GRID_SIZE, vector<int>(GRID_SIZE, NOTHING));
vector<vector<bool>> visited(GRID_SIZE, vector<bool>(GRID_SIZE, false));


int FindLiberties_Remove(int row, int col, int color)
{
    if(visited[row][col]) return 0;

    vector<vector<bool>> curr_visited(GRID_SIZE, vector<bool>(GRID_SIZE, false));
    vector<pair<int,int>> group;
    queue<pair<int,int>> q;

    q.push({row, col});
    curr_visited[row][col] = true;
    visited[row][col] = true;
    group.push_back({row, col});
    
    bool liberty = false;
    
    while(!q.empty())
    {
        int cur_i = q.front().first;
        int cur_j = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int adj_row = dir_row[dir] + cur_i;
            int adj_col = dir_col[dir] + cur_j;

            if(adj_row <= 0 || adj_row >= GRID_SIZE) continue;
            if(adj_col <= 0 || adj_col >= GRID_SIZE) continue;
            
            if(grid[adj_row][adj_col] == NOTHING) liberty = true;

            else if(grid[adj_row][adj_col] == color && curr_visited[adj_row][adj_col] == false)
            {
                curr_visited[adj_row][adj_col] = true;
                visited[adj_row][adj_col] = true;

                q.push({adj_row, adj_col});
                group.push_back({adj_row, adj_col});
            }
        }
    }
    
    if(!liberty)
    {
        for(auto &[i, j] : group) grid[i][j] = NOTHING;
        return group.size();
    }
    return 0;
}


void print_removes(int amount_removed_blacks, int amount_removed_whites)
{
    cout << amount_removed_blacks << " " << amount_removed_whites << "\n";
}

void action (int color, int row, int col)
{
    // Set piece
    grid[row][col] = color;

    // Clean other color with 0 liberties
    int current = color;
    int oponent = (current == BLACK) ? WHITE : BLACK;
    
    int amount_removed_current = 0;
    int amount_removed_oponent = 0;
    
    for(int dir = 0; dir < 4; dir++)
    {
        int i = dir_row[dir] + row;
        int j = dir_col[dir] + col;
        if(i <= 0 || i >= GRID_SIZE) continue;
        if(j <= 0 || j >= GRID_SIZE) continue;

        if(grid[i][j] == oponent)
            amount_removed_oponent += FindLiberties_Remove(i, j, oponent);
    }
    
    // Cleaning
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            visited[i][j] = false;
        }
    }
    
    amount_removed_current += FindLiberties_Remove(row, col, current);
    
    for(int dir = 0; dir < 4; dir++)
    {
        int i = dir_row[dir] + row;
        int j = dir_col[dir] + col;
        if(i <= 0 || i >= GRID_SIZE) continue;
        if(j <= 0 || j >= GRID_SIZE) continue;

        if(grid[i][j] == current)
            amount_removed_current += FindLiberties_Remove(i, j, current);
    }

    // Cleaning
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            visited[i][j] = false;
        }
    }

    if(current == BLACK) print_removes(amount_removed_current, amount_removed_oponent);
    if(current == WHITE) print_removes(amount_removed_oponent, amount_removed_current);
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> m;
    
    for(int i = 1; i <= m; i++)
    {
        int row, col; cin >> row >> col;

        if(i % 2 == 0)
            action(WHITE, row, col);
        else
            action(BLACK, row, col);
    }
}