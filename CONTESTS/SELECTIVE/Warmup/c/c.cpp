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
        vector<int> a(n);
#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        double w;
        int ox, oy; ox = oy = 0;
        int px, py; cin >> px >> py;
        int ax, ay; cin >> ax >> ay;
        int bx, by; cin >> bx >> by;

        double dist = ((px - ox)**2 + (py - oy)**2)**-2;
        double dist_ao = ((ox - ax)**2 + (oy - ay)**2)**-2; 
        double dist_ap = ((px - ax)**2 + (py - ay)**2)**-2; 
        double dist_bo = ((ox - bx)**2 + (oy - by)**2)**-2; 
        double dist_bp = ((px - bx)**2 + (py - by)**2)**-2;
        double dist_ab = ((ax - bx)**2 + (ay - by)**2)**-2;

        
        
    }
}
        
        for(int i = 0; i < n; i++)
        {
            int xorx = 0;
            int x = a[i];
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    xorx = xorx ^ a[j];
                }
            }            
            if(xorx == x)
            {
                cout << x << "\n";
                break;
            }
        }
    }
}