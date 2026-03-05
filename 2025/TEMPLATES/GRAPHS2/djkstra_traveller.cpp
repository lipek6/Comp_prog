#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

int intersections, streets, friends;
vector<vector<pair<int,int>>> AL;
vector<int> important_nodes;

void djkastra(int source, vector<int>& dist, vector<int>& parent);

// Home is at intersection number one and camping site is at intersection number N
int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    int case_num = 0;

    while(tc--)
    {
        case_num++;

        cin >> intersections >> streets >> friends;
        
        AL.clear();
        important_nodes.clear();

        AL.resize(intersections + 1);
        important_nodes.resize(friends + 2);
                
        for(int i = 0; i < streets; i++)
        {
            int pt1, pt2, len;
            cin >> pt1 >> pt2 >> len;
            
            AL[pt1].push_back({len, pt2});
            AL[pt2].push_back({len, pt1});
        }
        
        important_nodes[0] = 1;                                         // Source
        for(int i = 1; i <= friends; i++) cin >> important_nodes[i];    // Friends
        important_nodes[friends + 1] = intersections;                   // Destiny
        

        // Build matrix of all distances of the important nodes
        vector<vector<int>> dist_matrix  (intersections + 1, vector<int>(intersections + 1, INF));
        vector<vector<int>> parent_matrix(intersections + 1, vector<int>(intersections + 1, INF));

        for(int i = 0; i < important_nodes.size(); i++)
        {
            int node = important_nodes[i];
            djkastra(node, dist_matrix[node], parent_matrix[node]);
        }
        
        // Try all permutations of visiting order of the important nodes
        sort(important_nodes.begin() + 1, important_nodes.end() - 1);
        int minimal_distance = INF;
        do
        {
            int distance = 0;
            for(int j = 1; j < important_nodes.size(); j++)
            {
                int curr_node = important_nodes[j-1]; 
                int next_node = important_nodes[j];
                
                distance += dist_matrix[curr_node][next_node];
            }
            minimal_distance = min(minimal_distance, distance);
        }
        while(next_permutation(important_nodes.begin() + 1, important_nodes.end() - 1));
    
        cout << "Case " << case_num << ": " << minimal_distance << "\n";
    }
}

void djkastra(int source, vector<int>& dist, vector<int>& parent)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;

    heap.push({0, source});
    parent[source] = source;
    dist[source] = 0;

    while(!heap.empty())
    {
        auto [current_distance, current_node] = heap.top();
        heap.pop();

        if(dist[current_node] < current_distance) continue; // Case of trash on the heap

        for(auto& [local_distance, ajdacent_node] : AL[current_node])
        {
            int new_distance = dist[current_node] + local_distance; 
            
            if(dist[ajdacent_node] < new_distance) continue; // Case of trash on the heap

            dist[ajdacent_node] = new_distance;
            parent[ajdacent_node] = current_node;
            heap.push({new_distance, ajdacent_node});
        }
    }
    return;
}