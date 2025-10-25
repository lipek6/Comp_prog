#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    
    vector<string> matrix(n);

    for(int i = 0; i < n; i++) cin >> matrix[i];
    

    int count = 0;
    bool ok1 = false;
    bool ok2 = false;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ok1 = false;
            ok2 = false;
            if(matrix[i][j] == 'o')
            {
                for(int k = 0; k < n; k++)
                {
                    if(k != j && matrix[i][k] == 'o') ok1 = true;
                    if(k != i && matrix[k][j] == 'o') ok2 = true;
                    if(ok1 && ok2)
                    {
                        count++;
                        break;
                
                    }
                }
            }
        }
    }
    cout << count << "\n";
}