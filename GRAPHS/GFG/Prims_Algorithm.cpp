//! MINIMUM SPANNING TREE USING PRIM'S ALGORITHM
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
    // wt , node , parent 
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
    vector<bool>IsMST(V, 0);
    vector<int>parent(V); // temporary
    
    int cost = 0;
    pq.push({0,{0, -1}});
    
    while(!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        
        pq.pop();
        
        
        if(!IsMST[node]) // if node is not part of MST then make it 
        {
            IsMST[node] = 1;
            cost += wt;
            parent[node] = par;
            
            for(int j = 0; j < adj[node].size(); j++)
            {
                // node should be part of MST then only perform below operations
                if(!IsMST[adj[node][j][0]])
                { // wt , node, parent 
                    pq.push({adj[node][j][1], {adj[node][j][0], node}});
                }
            }
        }
    }
    
    return cost;
    }
};