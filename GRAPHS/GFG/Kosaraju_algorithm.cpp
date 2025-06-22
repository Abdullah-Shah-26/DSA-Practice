class Solution {
  public:
  
  void Toplogical(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s)
  {
      // mark as visited
      visited[node] = 1;
      
      // Look at all its neighbour
      for(int j = 0; j < adj[node].size(); j++)
      {
          if(!visited[adj[node][j]])
          Toplogical(adj[node][j], adj , visited, s);
      }
      // return aate time push in stach
      s.push(node);
  }
  
  void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited)
  {
      visited[node] = 1;
      
      for(int j = 0; j < adj[node].size(); j++)
      {
          if(!visited[adj[node][j]])
          DFS(adj[node][j], adj, visited );
      }
  }
  
  
    int kosaraju(vector<vector<int>> &adj) {
        // Topological sort
        int V = adj.size();
        
        stack<int>s;
        vector<bool>visited(V, 0);
        
        for(int i= 0; i< V; i++)
        {
            if(!visited[i])
            Toplogical(i, adj, visited, s);
        }
        // reverse the edges 
        vector<vector<int>>adj2(V);// adjlist 2 - reverse edges
        
        for(int i = 0; i < V; i++)
        {
            for(int j = 0;j < adj[i].size(); j++)
            {
                int u = i; 
                int v = adj[i][j]; // puri row mein jitne bhi elements hai uspar edges bhej rahe hay
                adj2[v].push_back(u);
            }
        }
        
        // pop the elem from stack
        // If the popped node is not visited yet 
        // SCC++
        // Apply DFS
        for(int i = 0; i < V; i++)
        {
            visited[i] = 0;
        }
        int SCC = 0;
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            
            if(!visited[node])
            {
                SCC++;
                DFS(node, adj2, visited);
            }
        }
    return SCC; 
    }
};