#include<bits/stdc++.h>
using namespace std;

enum {NO_ROAD = 0, CIRCLE_ROAD = 1, NEW_ROAD = 2};

// Yeah, that probably requires a matrix and not an adjacency list
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> matrix(n+1, vector<int>(n+1, NO_ROAD));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j == i+1)
            matrix[i][j] = CIRCLE_ROAD;
            else if(i == j+1)
            matrix[i][j] = CIRCLE_ROAD;
        }
    }
    matrix[n][1] = CIRCLE_ROAD;
    matrix[1][n] = CIRCLE_ROAD;

    string result = "";

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        if(matrix[a][b] == CIRCLE_ROAD)
        {
            result.append("i");
        }
        else if(matrix[a][b] == NO_ROAD)
        {
            result.append("o");
        }
    }

    cout << result << "\n";


}