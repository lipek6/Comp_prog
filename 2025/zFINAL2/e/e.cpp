#include<bits/stdc++.h>
using namespace std;

struct Point
{
    long long x, y;

    // Operadores para facilitar sintaxe vetorial
    bool operator<(const Point& other) const
        {return x < other.x || (x == other.x && y < other.y);}
    
    bool operator==(const Point& other) const
        {return x == other.x && y == other.y;}

    Point operator-(const Point& other) const
        {return {x - other.x, y - other.y};}
};

long long cross_product(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}

long long orientation(Point p, Point q, Point r)
{
    return cross_product(q - p, r - q);
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    Point p[3];

    while(tc--)
    {
        for(int i = 0; i < 3; i++) cin >> p[i].x >> p[i].y;
        
        long long where = orientation(p[0], p[1], p[2]);

        if (where == 0)
            cout << "TOUCH\n";
        
        else if(where > 0)
            cout << "LEFT\n";
    
        else
            cout << "RIGHT\n";
    }
    return 0;
}