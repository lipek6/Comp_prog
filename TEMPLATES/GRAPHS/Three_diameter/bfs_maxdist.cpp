#include<bits/stdc++.h>
#define UNVISITED -1

using namespace std;


// Basically, instead of running 'n' BFSs, I run one at the node 1, one at the node further away from one,
// and one at the node further away from this last node. I save all the distances for each of these BFSs and
// then I print the max of the two last searches.

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<vector<int>> AL(n+1);

    for(int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;

        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    
    vector<vector<int>> max_dists(3, vector<int>(n+1));
    int last_node = 1;
    for(int i = 0; i < 3; i++)
    {
        vector<int> dist(n+1, UNVISITED);
        queue<int> q;
        q.push(last_node);
        dist[last_node] = 0;

        while(!q.empty())
        {
            int source_node = q.front();
            q.pop();

            for(int adjacent_node : AL[source_node])
            {
                if(dist[adjacent_node] == UNVISITED)
                {
                    dist[adjacent_node] = dist[source_node] + 1;
                    q.push(adjacent_node);
                    last_node = adjacent_node;
                }
            }
        }
        copy(dist.begin(), dist.end(), max_dists[i].begin());
    }

    for(int i = 1; i <= n; i++)
    {
        cout << max(max_dists[1][i], max_dists[2][i]) << " ";
    }
    cout << "\n";
}