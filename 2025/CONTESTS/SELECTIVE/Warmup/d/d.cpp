#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        // Getting the coordinates
        int ox, oy;     ox = oy = 0;
        int px, py; cin >> px >> py;
        int ax, ay; cin >> ax >> ay;
        int bx, by; cin >> bx >> by;
        
        // Calculating the distances
        double dist_op = (double) sqrt(pow(ox - px, 2) + pow(oy - py, 2));
        double dist_oa = (double) sqrt(pow(ox - ax, 2) + pow(oy - ay, 2));
        double dist_ob = (double) sqrt(pow(ox - bx, 2) + pow(oy - by, 2));
        double dist_pa = (double) sqrt(pow(ax - px, 2) + pow(ay - py, 2));
        double dist_pb = (double) sqrt(pow(bx - px, 2) + pow(by - py, 2));
        double dist_ab = (double) sqrt(pow(ax - bx, 2) + pow(ay - by, 2));

        // Calculating the radius for each of the possible cases
        double both_in_a = max(dist_oa, dist_pa);                   // Putting 'o' and 'p' inside 'a'
        double both_in_b = max(dist_ob, dist_pb);                   // Putting 'o' and 'p' inside 'b'
        
        // These cases needs the circles to intersect
        double oa_pb     = max(max(dist_oa, dist_pb), dist_ab/2);   // Putting 'o' in 'a' and 'p' in 'b'
        double ob_pa     = max(max(dist_ob, dist_pa), dist_ab/2);   // Putting 'o' in 'b' and 'p' in 'a'
        // We used half of the distance between a and b, because the radius needs to be at least enough so that the circle of a touchs the circle of b


        //All possible radius have been calculated, we need to find the smaller radius;
        double w = min(min(both_in_a, both_in_b), min(oa_pb, ob_pa));

        // And that's it, how the fuck I was unable to do that during the contest?
        cout << setprecision(10) <<  w << "\n";
        //DO NOT FORGET THE SET PRECISION
    }
}