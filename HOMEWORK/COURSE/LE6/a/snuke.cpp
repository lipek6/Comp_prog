#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int dir_row[] = {1, 1, 0, -1, -1, -1, 0, 1};    // S, SE, E, NE, N, NW, W, SW
    int dir_col[] = {0, 1, 1, 1, 0, -1, -1, -1};    // S, SE, E, NE, N, NW, W, SW
    
    int h, w; cin >> h >> w;
    string snuke = "snuke";

    // Implicit graph
    vector<string> matrix(h);
    for(int i = 0; i < h; i++) cin >> matrix[i];

    // Checking the ajdacent directions of the current node
    int s = 0;
    bool possible = true;
    int i = 0;
    int j = 0;
    while(i != h-1 || j != w-1)
    {
        for(int dir = 0; dir < 8; dir++)
        {
            if(i + dir_row[dir] < 0 || i + dir_row[dir] >= h) continue;
            if(i + dir_col[dir] < 0 || i + dir_col[dir] >= w) continue;
            if(matrix[i + dir_row[dir]][j + dir_col[dir]] == snuke[s % 5])
            {
                s++;
                i += dir_row[dir];
                j += dir_col[dir];
            }
            else if(dir == 7) possible = false;
        }

        if (!possible)
        {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
}