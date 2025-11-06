#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;    // "The number of applicants, the number of apartments, and the maximum allowed difference"

    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    
    // Doing a BS for each apartment to find the best applicant for it
    int people_apartment = 0;
    for(int i = m - 1; i >= 0; i--)
    {
        if(people_apartment == n) break;
        int l = 0;
        int r = n - 1;
        int answer = -1;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            if(abs(a[mid] - b[i]) <= k) answer = mid;

            if(a[mid] <= b[i])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        if(answer != -1)
        {
            b.pop_back();
            people_apartment++;
        }
    }
    cout << people_apartment << "\n";
}