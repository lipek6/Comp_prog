#include<bits/stdc++.h>
using namespace std;

// This one is clearly a prefix sum question
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<long long> psum(n+1);
    vector<int> x(n);

    for(int i = 0; i < n; i++) cin >> x[i];

    int pop;
    psum[0] = 0;
    for(int i = 0; i < n; i++) 
    {
        cin >> pop;
        psum[i+1] = psum[i] + pop;
    }
    
    long long answer;
    int l, r;
    int q; cin >> q;
    while(q--)
    {
        cin >> l >> r;

        // To correct problems with the conversion of l and r to index, let's use iterators to point to the coordinates that are the closest to l and r
        vector<int>::iterator l_it = lower_bound(x.begin(), x.end(), l); // Finding where to place l (considering the available coordinates of the villages)
        vector<int>::iterator r_it = upper_bound(x.begin(), x.end(), r); // Finding where to place r (considering the available coordinates of the villages)
        int l_idx = l_it - x.begin();   //Turning the iterators into indexes
        int r_idx = r_it - x.begin();   //Turning the iterators into indexes

        answer = psum[r_idx] - psum[l_idx]; //The fact that psum is n + 1 makes unnecessary using any correctiosn on idxs here 
        cout << answer << "\n";
        
    }   //Now I will pray that this shit will
}