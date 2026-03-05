#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) 
        {
            if (parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}


int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n+1);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> n >> m;
    adj.resize(n+1);
    capacity.resize(n+1);

    for(int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back(b);
        capacity[a].push_back(c);
    }
    cout << maxflow(1, n) << "\n";
}
