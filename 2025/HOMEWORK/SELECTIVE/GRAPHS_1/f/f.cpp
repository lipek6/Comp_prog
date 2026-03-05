#include<bits/stdc++.h>
#define UNVISITED 1e9
using namespace std;

//void PrintMatrix(vector<vector<int>> dist);

int n, m; 
int dir_row[4] = {-1, +1, +0, +0}; // Up, Down, Left, Right
int dir_col[4] = {+0, +0, -1, +1}; // Up, Down, Left, Right

vector<vector<char>> matrix;
vector<vector<int>> Mdist;
vector<vector<int>> Adist;
pair<int, int> better_point = {-1, -1};
string str_path;

void ReleaseMonsters(vector<pair<int,int>>& monster)
{
    queue<pair<int,int>> q; 

    for(int i = 0; i < monster.size(); i++)
    {
        q.push({monster[i].first, monster[i].second});
        Mdist[monster[i].first][monster[i].second] = 0;
    }
    
    while(!q.empty())
    {    
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();
        
        for(int dir = 0; dir < 4; dir++)
        {
            int new_row = cur_row + dir_row[dir];
            int new_col = cur_col + dir_col[dir];
            
            if(new_row >= n || new_row < 0) continue;
            if(new_col >= m || new_col < 0) continue;
            if(matrix[new_row][new_col] == '#') continue;
            if(Mdist[new_row][new_col] != UNVISITED) continue;
            
            Mdist[new_row][new_col] = Mdist[cur_row][cur_col] + 1;
            
            q.push({new_row, new_col});
        }
    }
}

void TryToEscape(pair<int,int>& dude)
{
    queue<pair<int,int>> q;
    q.push(dude);
    Adist[dude.first][dude.second] = 0;
    
    while(!q.empty())
    {    
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();
        
        for(int dir = 0; dir < 4; dir++)
        {
            int new_row = cur_row + dir_row[dir];
            int new_col = cur_col + dir_col[dir];
            
            if(new_row >= n || new_row < 0) continue;
            if(new_col >= m || new_col < 0) continue;
            if(matrix[new_row][new_col] != '.') continue;
            if(Adist[new_row][new_col] != UNVISITED) continue;
            
            Adist[new_row][new_col] = Adist[cur_row][cur_col] + 1;

            if(Adist[cur_row][cur_col] + 1 >= Mdist[new_row][new_col]) continue;

            if((new_row == n-1 || new_col == m-1) || (new_row == 0 || new_col == 0))
            {
                better_point.first  = new_row;
                better_point.second = new_col;
                return;
            }
            
            q.push({new_row, new_col});
        }
    }
}

// Cannot be a fucking DFS because of stack overflow
void GetPath(int cur_row, int cur_col)
{    
    while(matrix[cur_row][cur_col] != 'A')
    {
        for(int dir = 0; dir < 4; dir++)
        {
            int new_row = cur_row + dir_row[dir];
            int new_col = cur_col + dir_col[dir];
                        
            if(new_row >= n || new_row < 0) continue;
            if(new_col >= m || new_col < 0) continue;
            if(matrix[new_row][new_col] == 'M') continue;
            if(matrix[new_row][new_col] == '#') continue;
            if(Adist[new_row][new_col] != Adist[cur_row][cur_col] - 1) continue;
                        
            // INVERSED
            if(dir == 0) str_path += 'D';
            if(dir == 1) str_path += 'U';
            if(dir == 2) str_path += 'R';
            if(dir == 3) str_path += 'L';   
            
            cur_row = new_row;
            cur_col = new_col;
            break;
        }
    }
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    matrix.resize(n, vector<char>(m));
    Mdist.assign(n, vector<int>(m, UNVISITED)); 
    Adist.assign(n, vector<int>(m, UNVISITED));

    vector<pair<int,int>> M;
    pair<int, int> A;


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            char point; cin >> point;
            matrix[i][j] = point;
            
            if(point == 'M')
            {
                M.push_back({i, j});
                continue;
            }
            
            if(point == 'A')
            {
                A.first  = i;
                A.second = j;
                continue;
            }
        }
    }

    // Can escape immediatly
    if((A.first == 0 || A.first == n-1) || (A.second == m-1 || A.second == 0))
    {
        cout << "YES\n";
        cout << "0\n";
        return 0;
    }


    ReleaseMonsters(M);    
    TryToEscape(A);
    
    if(better_point.first == -1 || better_point.second == -1)
    {
        cout << "NO\n";
        return 0; 
    }
    else
    {
        GetPath(better_point.first, better_point.second);
        cout << "YES\n";
        cout << str_path.size() << "\n";
        reverse(str_path.begin(), str_path.end());
        cout << str_path << "\n";
    }

    //PrintMatrix(Mdist);
    //cout << "\n";
    //PrintMatrix(Adist);
    //cout << better_point.first << "\n";
    //cout << better_point.second << "\n";
}


//void PrintMatrix(vector<vector<int>> dist)
//{
//    for(int i = 0; i < n; i++)
//    {
//        for(int j = 0; j < m; j++)
//        {
//            if(dist[i][j] >= 0)
//                cout << "+" << dist[i][j] << " ";
//            else
//                cout << dist[i][j] << " ";
//        }
//        cout << "\n";
//    }
//}