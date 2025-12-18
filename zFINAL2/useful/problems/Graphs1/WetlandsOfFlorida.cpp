#include<bits/stdc++.h>
using namespace std;
int dir_row[] = {1, 1, 0, -1, -1, -1, 0, 1};    // S, SE, E, NE, N, NW, W, SW
int dir_col[] = {0, 1, 1, 1, 0, -1, -1, -1};    // S, SE, E, NE, N, NW, W, SW

vector<string>matrix;
int rows_max;
int cols_max;



int floodfill(int row, int col)
{
    if(row < 0 || row >= rows_max) return 0;    // Out of bounds checking
    if(col < 0 || col >= cols_max) return 0;    // Out of bounds checking

    if(matrix[row][col] != 'W') return 0;       // Land checking

    int area = 1;
    matrix[row][col] = '.';
    for(int dir = 0; dir < 8; dir++)
    {
        area += floodfill(row + dir_row[dir], col + dir_col[dir]);
    }
    return area;
}



int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    cin.ignore();
    cin.ignore();
    string line;
    while(t--)
    {
        matrix.clear();
        int rows = 0;
        while(getline(cin, line) && !line.empty())
        {
            if(line[0] == 'L' || line[0] == 'W')
            {
                matrix.push_back(line);
                rows++;
            }
            else break;
        }
        rows_max = rows;
        cols_max = matrix[0].size();
        vector<string> matrix_copy = matrix;
        int row, col;

        stringstream ss(line);
        ss >> row >> col;
        int wet_area = floodfill(row - 1, col - 1);
        cout << wet_area << "\n";
        matrix = matrix_copy;
        while(getline(cin, line) && !line.empty())
        {
            stringstream ss(line);
            ss >> row >> col;
            matrix_copy = matrix;
            
            int wet_area = floodfill(row - 1, col - 1);
            cout << wet_area << "\n";
            matrix = matrix_copy;
        }
        if (t > 0)
        {
            cout << "\n";
        }    
    }
}