class Solution {
  public:
  
  bool DFS(int node, vector<vector<int>>&adj, vector<bool>&visited, int &count, int N )
  {
      visited[node] = 1;
      count++;
      
      // base case all nodes visited
      if(count == N)
      return 1;
      
      // recursively check for other unvisited nodes
      for(int j = 0 ; j < adj[node].size(); j++)
      {
          if(!visited[adj[node][j]]  &&   DFS(adj[node][j], adj, visited ,count ,N))
          return 1;
      }
      
      visited[node] = 0;// backtraking step to explore all other options
      count--;
      return 0;
  }
  
    bool check(int N, int M, vector<vector<int>> edges) {
     // create an adjacency list
     vector<vector<int>>adj(N);
     int V = edges.size();
     
     for(int i = 0 ; i < edges.size();i++)
     {
         adj[edges[i][0] - 1].push_back(edges[i][1] -1 );
         adj[edges[i][1] - 1].push_back(edges[i][0] -1 );
     }
     
     vector<bool>visited(V, 0);
     int count = 0;
     
     for(int i = 0 ; i < N ; i++)
     {
     if(DFS(i, adj , visited, count , N))
     {
         return 1;
     }
     }
     return 0;   
    }
};
