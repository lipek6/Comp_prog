    #include<bits/stdc++.h>
    using namespace std;

    // Possible states of the nodes
    enum {UNVISITED = -1, EXPLORED = -2, VISITED = -3};

    // Adjacency list to store the connections of the graph nodes
    vector<vector<int>> AL;

    // Vector to store the state of the nodes()
    vector<int> dfs_num;
    vector<int> dfs_parent;
    bool cycle = false;
    // Funtion to run a deep-first search on the given graph
    void dfs (int u)
    {
        dfs_num[u] = VISITED;
        for(int v = 0; v < AL[u].size(); v++)
        {
            if(AL[u][v] == UNVISITED)
                dfs(AL[u][v]);
        }
    }

    // Vector to store the topologicaly sorted graph
    vector<int> topologicaly_sorted;

    // Funtion to topologicaly sort a graph with a deep-first search implementation
    void topo_sort(int u)
    {
        dfs_num[u] = VISITED;
        for(int v = 0; v < AL[u].size(); v++)
        {
            if(AL[u][v] == UNVISITED)
                topo_sort(AL[u][v]);
        }
        topologicaly_sorted.push_back(u);
    }

    void cycleCheck(int u)
    {
        dfs_num[u] = EXPLORED;
        for(auto &v : AL[u])
        {
            if(dfs_num[v] == UNVISITED)
            {
                dfs_parent[v] = u;
                cycleCheck(v);
            }
            else if(dfs_num[v] == EXPLORED)
            {
                cycle = true;
            }
            else if(dfs_num[v] == VISITED)
            {
                cycle = true;
            }
        }
        dfs_num[u] = VISITED;
    }


    // Cycle checking question
    int main (void)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int n; cin >> n;
        vector<string> word(n);
        for(int i = 0; i < n; i++)
        {
            cin >> word[i];
            for(int j = 0; j < word[i].size()-1; j++)
            {
                AL[word[i][j]].push_back(word[i][j+1]);
            }
        }
        int V = 26;
        dfs_num.assign(V, UNVISITED);
        dfs_parent.assign(V, -1);
        topologicaly_sorted.clear();

        for(int u = 0; u < V; u++)
        {
            if(dfs_num[u] == UNVISITED)
            {
                cycleCheck(u);   
            }
        }
        if(cycle)
        {
            cout << "NAO" << "\n";
            return 0;
        }

        dfs_num.assign(V, UNVISITED);
        dfs_parent.assign(V, -1);

        for(int u = 0; u < V; u++)
        {
            if(dfs_num[u] == UNVISITED)
            {
                topo_sort(u);
            }
        }

        cout << "SIM" << "\n";
        reverse(topologicaly_sorted.begin(), topologicaly_sorted.end());
        for(int i = 0; i < topologicaly_sorted.size(); i++)
        {
            cout << topologicaly_sorted[i];
        }
        cout << "\n";
    }