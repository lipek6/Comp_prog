#include<bits/stdc++.h>
using namespace std;

int n, m;               
int home_row, home_col; 
int ware_row, ware_col;
int min_stamps = 11;
vector<vector<int>> sector;

void TryAllPatterns(int current_stamp, vector<bool>& pattern);
bool try_to_reach(vector<bool>& pattern);
int count_stamps(const vector<bool>& pattern);

int dir_row[4] = {-1, +1, +0, +0};
int dir_col[4] = {+0, +0, -1, +1};

void TryAllPatterns(int current_stamp, vector<bool>& pattern)
{
    if (current_stamp > 10) 
    {
        int stamps = count_stamps(pattern);
        if (stamps >= min_stamps) return;

        if (try_to_reach(pattern)) min_stamps = stamps;
        
        return;
    }

    pattern[current_stamp] = false;
    TryAllPatterns(current_stamp + 1, pattern);

    pattern[current_stamp] = true;
    TryAllPatterns(current_stamp + 1, pattern);
}


bool try_to_reach(vector<bool>& pattern)
{
    int start_stamp = sector[home_row][home_col];
    int end_stamp = sector[ware_row][ware_col];

    if(pattern[start_stamp] == false) return false;
    if(pattern[end_stamp] == false)   return false;

    queue<pair<int, int>> q; q.push({home_row, home_col});
    
    vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
    visited[home_row][home_col] = true;

    while (!q.empty()) 
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (row == ware_row && col == ware_col) return true;

        for(int dir = 0; dir < 4; dir++) 
        {
            int adj_row = dir_row[dir] + row;
            int adj_col = dir_col[dir] + col;

            if(adj_row <= 0 || adj_row > n) continue;
            if(adj_col <= 0 || adj_col > m) continue;
            if(visited[adj_row][adj_col])     continue;

            int stamp_needed = sector[adj_row][adj_col];
                
            if(pattern[stamp_needed])
            {
                visited[adj_row][adj_col] = true;
                q.push({adj_row, adj_col});
            }
        }
    }
    return false;
}

int count_stamps(const vector<bool>& pattern)
{
    int count = 0;
    for(bool stamp : pattern)
        if(stamp) count++;
    return count;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> home_row >> home_col;
    cin >> ware_row >> ware_col;
    
    sector.resize(n+1, vector<int>(m+1));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> sector[i][j];
        }
    }
    
    vector<bool> pattern(11, false);
    TryAllPatterns(1, pattern);

    cout << min_stamps << "\n";
}