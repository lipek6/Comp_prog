#include<bits/stdc++.h>
using namespace std;

vector<string> board(8);
bitset<30> rw, ld, ld;

long long ans = 0;
int row[8];
int a, b;

void backtrack(int col)
{
    if(col == 8)
    {
        ans++;
        return;
    }

    for(int row = 0; row < 8; row++)
    {
            // Is avaliable             free row    free diagonal right      free left diagonal
        if((board[row][col] != '*') && !rw[row] && !ld[row - col + 8 - 1] && !rd[row+col])
        {
            rw[row] = ld[row - col + 8 - 1] = rd[row+col] = true;            // Try it
            backtrack(col+1);
            rw[row] = ld[row - col + 8 - 1] = rd[row+col] = false;           // Untry it
        }
    }
}


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 8; i++) cin >> board[i];
    backtrack(0);

    cout << ans << "\n";
}