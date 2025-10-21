#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    int steps = 0;
    while (n != 0)
    {
        int max_digit = 0;
        
        int temp = n;
        while(temp != 0)        // Finds the greatest digit of n
        {
            int last_digit = temp % 10;             // Gets the last digit of n
            max_digit = max(max_digit, last_digit); // Finds the maximum between all the digits of n (max starts at 0)
            temp = temp / 10;                       // Removes the last digit of n, so we can look ar the other digits at last_digit and compare than to find the greatest
        }
        n -= max_digit;         // Removes the greatest digit of n from n
        steps++;                // Counts the steps
    }

    cout << steps << "\n";
}