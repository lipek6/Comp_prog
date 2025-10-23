#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    
    int t; cin >> t;    // Number of test cases
    int n;              // Number of nodes of the graph in the test case
    bool conection;     // There is or is not a connection between node j and i 

    for(int t_count = 1; t_count <= t; t++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; i < j; j++)
            {
                cin >> conection;
                if(conection)
                {

                }
            }
        }
        cout << "Case " << t_count << ":" << endl;
        
    }


}