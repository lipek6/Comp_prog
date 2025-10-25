#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int ox, oy; ox = oy = 0;
        int px, py; cin >> px >> py;
        int ax, ay; cin >> ax >> ay;
        int bx, by; cin >> bx >> by;

        double dist    = (double) sqrt(((px - ox)*(px - ox) + (py - oy)*(py - oy)));
        double dist_ao = (double) sqrt(((ox - ax)*(ox - ax) + (oy - ay)*(oy - ay))); 
        double dist_ap = (double) sqrt(((px - ax)*(px - ax) + (py - ay)*(py - ay))); 
        double dist_bo = (double) sqrt(((ox - bx)*(ox - bx) + (oy - by)*(oy - by))); 
        double dist_bp = (double) sqrt(((px - bx)*(px - bx) + (py - by)*(py - by)));
        double dist_ab = (double) sqrt(((ax - bx)*(ax - bx) + (ay - by)*(ay - by)));

        double dist_o = min(dist_ao, dist_bo);
        double dist_p = min(dist_ap, dist_bp);
        double w      = max(dist_o, dist_p); 
        if(w < dist_ab/2) w = dist_ab/2;

        cout << w << "\n";        
    }
}