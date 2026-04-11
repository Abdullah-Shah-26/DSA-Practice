class Solution {
  public:
  void DFS(int node , vector<int>adj[], vector<bool> &visited)
  {
      // first mark as visited
      visited[node] = 1;
      
      for(int j = 0; j < adj[node].size(); j++)
      {
          if(!visited[adj[node][j]])
          DFS(adj[node][j], adj , visited);
      }
  }
  
  
    int isCircle(vector<string> &A) {
        
        int N = A.size();
        // Edges create karna hay 
        // Adjacency List 
        // a - z 
        // a - 0    b - 1     c - 2    d - 3    z - 25
        vector<int>adj[26];
        vector<int>InDeg(26, 0);
        vector<int>OutDeg(26, 0);
        
        
        
        for(int i = 0; i < N; i++)
        {
            string temp = A[i];
            // first char u last char v 
            // edge u to v
            char u = temp[0] - 'a'; // why '-a' to convert it to no 
            char v = temp[temp.size()-1] - 'a';
            adj[u].push_back(v);
            
            OutDeg[u]++;
            InDeg[v]++;
        }
        
        // Check if Elurian Circuit Exist
    // Find indegree & outdegree
    
    for(int i = 0; i < 26; i++)
    {
        if(InDeg[i] != OutDeg[i])
        return 0;
    }
    
    // check if  All the edges are part of one component
    // or jiski indeg and outdeg exist they should be part of single component
    // apply DFS
    vector<bool>visited(26, 0);
    int node = A[0][0] - 'a';
    DFS(node , adj, visited);


// check for nodes whose indeg/outdeg exist but arent vistied - EC doesnt exist
// since there would be an edge that was not part of current component and remains unvisited
    for(int i = 0; i < 26; i++)
    {
        if(InDeg[i] && !visited[i])
        return 0;
    }
    
    return 1;
    }
};