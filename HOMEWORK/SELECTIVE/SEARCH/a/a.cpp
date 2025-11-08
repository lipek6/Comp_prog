#include<bits/stdc++.h>
using namespace std;

#define G_SIZE 9
#define SUBG_SIZE 3

vector<vector<int>> sudoku(G_SIZE, vector<int>(G_SIZE));


bool CheckNumber(int y, int x, int num)
{
    int x0 = (x / SUBG_SIZE) * SUBG_SIZE;
    int y0 = (y / SUBG_SIZE) * SUBG_SIZE;

    for(int i = 0; i < G_SIZE; i++)     
    {
        if(sudoku[y][i] == num)
            return false;
        
        if(sudoku[i][x] == num)
            return false;    
    }

    for(int i = 0; i < SUBG_SIZE; i++)     
    {
        for(int j = 0; j < SUBG_SIZE; j++)
        {
            if(sudoku[y0 + i][x0 + j] == num)
                return false;
        }
    }
    return true;
}


bool SolveSudoku()
{
    for(int i = 0; i < G_SIZE; i++)             // Row traversal
    {
        for(int j = 0; j < G_SIZE; j++)         // Collum traversal
        {
            if(sudoku[i][j] == 0)
            {
                for(int num = 1; num < 10; num++)   // Trying numbers
                {
                    if(CheckNumber(i, j, num))
                    {
                        sudoku[i][j] = num;
                        if (SolveSudoku()) return true;
                        sudoku[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}





int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while(tc--)
    {
        for(int i = 0; i < G_SIZE; i++)
        {
            for(int j = 0; j < G_SIZE; j++)
            {
                cin >> sudoku[i][j];
            }
        }

        bool solved = SolveSudoku();

        if(solved)
        {
            for(int i = 0; i < G_SIZE; i++)
            {
                for(int j = 0; j < G_SIZE; j++)
                {
                    cout << sudoku[i][j] << " ";
                }
                cout << "\n";
            }
        }
        else
        {
            cout << "No solution" << "\n";
        }

        sudoku.clear();
    }
}