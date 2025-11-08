#include<bits/stdc++.h>
using namespace std;

int n, k;
int ways;
vector<vector<bool>> board;

bool SolveBoard()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(CheckBoard(i, j))
            {
                board[i][j] = true;
                if (SolveBoard()) return true;
                board[i][j] = false;
            }
        }
        return false;
    }
    ways++;
    return true;
}








int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> n >> k)
    {
        if(n == 0 && k == 0) break;

        board.resize(n, vector<bool>(n));

        SolveBoard();

        cout << ways << endl;
    }
}