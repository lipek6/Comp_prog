#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> board;

int GetSum(int y, int x)
{
    int sum = 0;
    int i = 0;

    while(i < max(n, m))
    {
        if(y + i < n && x + i < m) sum += board[y+i][x+i];
        if(i != 0)
        {
            if(y + i < n && x - i >= 0) sum += board[y+i][x-i];
            
            if(y - i >= 0 && x + i < m) sum += board[y-i][x+i];
            
            if(y - i >= 0 && x - i >= 0) sum += board[y-i][x-i];
        }
        i++;
    }

    return sum;
}


int SolveMaxSum()
{
    int max_sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            max_sum = max(GetSum(i, j), max_sum);
        }
    }        
    return max_sum;
}




int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int tc; cin >> tc;
    
    while(tc--)
    {
        cin >> n >> m;
        board.resize(n, vector<int>(m));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> board[i][j];
            }
        }        

        cout << SolveMaxSum() << "\n";

        board.clear();
    }
}