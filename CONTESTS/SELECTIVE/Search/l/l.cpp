#include<bits/stdc++.h>
using namespace std;

long long sum = 0;
int n;
vector<vector<int>> skill_grid;
vector<vector<bool>> got_grid;

bool BeenChoose(int y, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(got_grid[y][i] == true)
            return true;
        if(got_grid[i][x] == true)
            return true;
    }
    return false;
}


bool FindSum()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!BeenChoose(i, j))
            {
                sum += skill_grid[i][j];
                got_grid[i][j] = true;
                
                if(FindSum()) return true;

                got_grid[i][j] = false;
                sum -= skill_grid[i][j];
                return false;
            }
        }
    }
    
    return true;
}



// Backtracking?
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    skill_grid.resize(n, vector<int>(n));
    got_grid.resize(n, vector<bool>(n));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> skill_grid[i][j];
        }
    } 

    FindSum();

    cout << sum << "\n";
}