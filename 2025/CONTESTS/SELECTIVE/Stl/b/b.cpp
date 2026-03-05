#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        int grid_size = (int) sqrt(n); 

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        
        bool stop = false;

        for(int i = 0; i < n; i++)
        {
            set<int> gd;    // grid
            set<int> cl;    // collum
            set<int> rw;    // row
            for(int j = 0; j < n; j++)
            {
                if(rw.count(matrix[i][j]))
                {
                    cout << "no" << "\n";
                    stop = true;
                    break;
                }
                if(cl.count(matrix[j][i]))
                {
                    cout << "no" << "\n";
                    stop = true;
                    break;                    
                }
                if(gd.count(matrix[i][j]) && j < grid_size - 1 && i != j)
                {
                    cout << "no" << "\n";
                    stop = true;
                    break;                    
                }
                if(gd.count(matrix[j][i]) && i < grid_size - 1 && i != j)
                {
                    cout << "no" << "\n";
                    stop = true;
                    break;                    
                }
                if(j > grid_size - 1) gd.clear();
                if(i > grid_size - 1) gd.clear();
                rw.insert(matrix[i][j]);
                cl.insert(matrix[j][i]);
                gd.insert(matrix[i][j]);
                gd.insert(matrix[j][i]);
            }
            if(stop) break;
        }
        if(!stop) cout << "yes" << "\n";
    }
}
