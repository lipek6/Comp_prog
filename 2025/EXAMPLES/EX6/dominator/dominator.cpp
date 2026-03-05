#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> AL;
vector<int> dfs_num;
vector<int> dominance;

void print_line (int n)
{
    cout << "+";
    for(int i = 0; i < (n * 2) - 1; i++) 
        cout << "-";
    cout << "+" << endl; 
}


void dfs (int u, int x)
{
    dfs_num[u] = 1;
    if(u == x) return;
    
    for(int i = 0; i < AL[u].size(); i++)
    {
        int adjacent = AL[u][i];
        if(dfs_num[adjacent] == 0)
            dfs(adjacent, x);   
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // The idea of this problem is to disable all the outgoing edges of X and then run a dsf again to check if we can reach Y;
    // If we cannot reach Y anymore, that means that vertex X dominates vertex Y.

    int t; cin >> t;    // Number of test cases
    int n;              // Number of nodes of the graph in the test case
    bool conection;     // There is or is not a connection between node j and i 
    
    
    for(int t_count = 1; t_count <= t; t++)
    {
        cin >> n;
        AL.resize(n);
        dfs_num.resize(n);
        fill(dfs_num.begin(), dfs_num.end(), 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> conection;
                if(conection)
                {
                    AL[i].push_back(j);
                }
            }
        }
        
        dfs(0, -1);
        vector<int> dfs_num_og;
        copy(dfs_num.begin(), dfs_num.end(), dfs_num_og.begin());

        int result[n][n];
        for(int x = 1; x < n; x++)
        {
            for(int y = 1; y < n; y++)
            {
                fill(dfs_num.begin(), dfs_num.end(), 0);
                dfs(0, x);
                if(dfs_num[y] == 0)
                {
                    result[x][y] = 1;
                }
                else
                {
                    result[x][y] = 0;
                }
            }
        }



        cout << "Case " << t_count << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            print_line(n);
            cout << "|";
            for (int j = 0; j < n; j++)
            {
                cout << result[i][j] << "|";
            }
            cout << endl;
        }
    
    }



}