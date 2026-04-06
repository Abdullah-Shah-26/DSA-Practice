class Solution {
public:
    void DFS(int node, int parent, vector<vector<int>> &adj,vector<int> &disc ,vector<int> &low, vector<bool>&visited, vector<vector<int>>&Bridges, int &count)
    {
        disc[node] = low[node] = count;
        visited[node] = 1;

        for(int j = 0; j < adj[node].size(); j++)
        {
            int neig = adj[node][j];
            // 3 main conditions 
            if(neig == parent )
            continue;
            else if(visited[neig]) // neighbour already visited
            {
                low[node] = min(low[node] , low[neig]);
            }
            else// neighbour not visited
            {
                count++;
                DFS(neig, node, adj , disc, low, visited, Bridges, count);
                low[node] = min(low[node], low[neig]);
                // Check if bridge exist or not
                if(low[neig] > disc[node])
                {
                    vector<int>temp;
                    temp.push_back(node);
                    temp.push_back(neig);
                    Bridges.push_back(temp);
                }
                
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Make an adjacency List
        vector<vector<int>>adj(n);
        for(int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>>Bridges;
        // discovery time
        vector<int>disc(n);
        vector<int>low(n); // stores the lowest possible node that a node can reach

        vector<bool>visited(n,0);
        int count = 0;

        DFS(0,-1 , adj , disc , low , visited, Bridges , count );

        return Bridges;
    }
};