#include<bits/stdc++.h>
#define UNVISITED 1e9
using namespace std;

int dir_row[4] = {-2, +2, +2, -2}; // Up_rigth, Up_left, Down_right, Down_left
int dir_col[4] = {+1, -1, +1, -1}; // Up_rigth, Up_left, Down_right, Down_left

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string square1, square2;
    while(cin >> square1 >> square2)
    {
        vector<vector<int>> table(9, vector<int>(9, UNVISITED));
        int moves = 0;

        int source_col = square1[0] - 97 + 1;
        int source_row = square1[1] - 48;

        int destiny_col = square2[0] - 97 + 1;
        int destiny_row = square2[1] - 48;

        table[source_row][source_col] = 0;

        queue<pair<int,int>> q; q.push({source_row, source_col});
        
        if()
        bool stop = false;
        while(!q.empty())
        {
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();

            for(int dir = 0; dir < 4; dir++)
            {
                int new_row = dir_row[dir] + curr_row;
                int new_col = dir_col[dir] + curr_col;

                if(new_row <= 0 || new_row >= 9) continue;
                if(new_col <= 0 || new_col >= 9) continue;
                if(table[new_row][new_col] != UNVISITED) continue;

                q.push({new_row, new_col});
                table[new_row][new_col] = table[curr_row][curr_col] + 1;
                
                if(new_row == destiny_row && new_col == destiny_col)
                {
                    cout << "To get from " << square1 << " to " << square2 << " takes " << table[new_row][new_col] <<" knight moves.\n";
                    break;
                    stop = true;
                }
            }
            if(stop) break;
        }
    }
}