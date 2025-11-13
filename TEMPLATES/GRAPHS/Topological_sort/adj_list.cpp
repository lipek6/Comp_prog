#include<bits/stdc++.h>
using namespace std;


int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, greater<int>> clean_nodes;
    vector<vector<int>> AL(26);
    vector<int> in_degree(26, 0);
    vector<char> topological_order;
    string word;
    
    int n; cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> word;
        for(int j = 0; j < word.length() - 1; j++)
        {
            int char1 = word[j] - 'a';
            int char2 = word[j+1] - 'a';
            
            bool redundant = false;
            for(int pointed_node: AL[char1])
            {
                if(pointed_node == char2)
                {
                    redundant = true;
                    break;
                }
            }

            if(!redundant && char1 != char2)
            {
                AL[char1].push_back(char2);
                in_degree[char2]++;
            }
        }
    }
    
    for(int u = 0; u < 26; u++)
    {
        if(in_degree[u] == 0)
            clean_nodes.push(u);
    }

    // BFS on the node that have in_degree == 0
    while(!clean_nodes.empty())
    {
        int the_node = clean_nodes.top();
        clean_nodes.pop();
        
        topological_order.push_back(the_node + 'a');    

        for(int node : AL[the_node])
        {
            in_degree[node]--;
            if(in_degree[node] == 0)
                clean_nodes.push(node);
        }

    }
    
    for(int u = 0; u < 26; u++)
    {
        if(in_degree[u] > 0)
        {
            cout << "NAO" << "\n";
            return 0;
        }
    }
    cout << "SIM" << "\n";
    for(int i = 0; i < topological_order.size(); i++)
    {
        cout << topological_order[i];
    }
    cout << "\n"; 

}