class Solution {
  public:
  
  // function to find ultimate parent 
  int FindParent(int u, vector<int>&parent){
      
      if(u == parent[u])
      return u; 
      
      // Path Compression 
      return parent[u] = FindParent(parent[u], parent);
  }
  
  void UnionByRank(int u, int v, vector<int>&parent, vector<int>& rank )
  {
      
      int pu = FindParent(u, parent);
      int pv = FindParent(v, parent);
      
      // after finding ultimate parent merge on basis of rank 
      // chote vale ko bade wale ke saath merge karna hay
      if(rank[pu] > rank[pv])
      {
          parent[pv] = pu;
      }
      else if(rank[pu] < rank[pv])
      {
          parent[pu] = pv;
      }
      else{ // can merge any with any since ranks are same
          parent[pv] = pu;
          rank[pu]++;
      }
      
  }
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        // Kruskal Algorithm 
        vector<int>parent(V); // Ultimate parent will help us determine the set
        vector<int>rank(V, 0); // Help us merge the set
        
        
        for(int i =0 ; i < V; i++)
        parent[i] = i;
        
        // pq min heap wt , u , v       
                 // Insert all the edges in min heap
                 vector<pair<int, pair<int, int>>>temp;
         for(int i = 0; i <V; i++){
             for(int j = 0; j < adj[i].size(); j++)
             {
                 temp.push_back({adj[i][j][1], {i, adj[i][j][0]}});
             }
         }
        
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq(temp.begin(),temp.end());
         

         int cost = 0;
         int edges = 0;
         
         while(!pq.empty())
         {
             int wt = pq.top().first;
             int u = pq.top().second.first;
             int v = pq.top().second.second;
             pq.pop();
             
             // Check if u & v are in different set 
            if(FindParent(u, parent)!= FindParent(v, parent)){
                // merge based on union by rank
                cost += wt; // calculates the cost of MInimum spanning tree that is created 
                UnionByRank(u, v , parent , rank);
                edges++;
                
            }
            // since MST is a tree and a tree has n-1 edges
             if(edges == V-1)
             break;
         }
         return cost;
    }
};
space complexity 