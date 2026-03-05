#include<bits/stdc++.h>
using namespace std;

int h, w;
int dr[] = {-1, +1, 0, 0};    // UP, DOWN, LEFT, RIGHT
int dc[] = {0, 0, -1, +1};    // UP, DOWN, LEFT, RIGHT
vector<vector<vector<bool>>> visited;
vector<string> matrix;
string snuke = "snuke";

void dfs(int i, int j, int s)   // s is the last character that we came from, because a path to the end maybe will need to visit something that we already visited from another possible path
{
    
    visited[i][j][s] = 1;
    int new_s = (s + 1) % 5;

    for(int k = 0; k < 4; k++)
    {
        int new_i = i+dr[k];
        int new_j = j+dc[k];

        if((new_i < 0 || new_j < 0) || (new_i >= h || new_j >= w))
            continue;
        if(visited[new_i][new_j][new_s] == 1)
            continue;
        if(snuke[new_s] != matrix[new_i][new_j])
            continue;

        dfs(new_i, new_j, new_s);
    }

}



int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    
    visited.resize(h, vector<vector<bool>>(w, vector<bool>(5)));
    matrix.resize(h);
    for(int i = 0; i < h; i++) cin >> matrix[i];

    if(matrix[0][0] != 's')
    {
        cout << "No" << "\n";
        return 0;
    }
    
    // We just need to run a dfs on the nodes that are ajdacent to 0,0, the dfs will work out the rest
    dfs(0,0,0);
    for(int i = 0; i < 5; i++)
    {
        if(visited[h-1][w-1][i] == 1)
        {
            cout << "Yes" << "\n";
            return 0;    
        }
    }
    cout<< "No" << "\n";
}