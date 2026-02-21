class Solution {
  public:
  void DFS(int node, vector<int> adj[], vector<bool>&visited)
  {
      visited[node] = 1;
      
      for(int j = 0; j< adj[node].size(); j++)
      {
          if(!visited[adj[node][j]])
          DFS(adj[node][j], adj , visited);
      }
  }
  
    int isEulerCircuit(int V, vector<int> adj[]) {
    // Euler Circuit : 2
    // calculate degree of each node
    // all nodes should have even degree
    // All non 0 degree node should  be connected
    
    // Euler path : 1
    // calculate degree of each node
    // zero or two nodes can have odd degree and remaining have even degree
    // all non zero degree nodes should be connected
    
    
    vector<int>Deg(V, 0);
    int Odd_Deg = 0;
    for(int i = 0; i < V; i++)
    {
        Deg[i] = adj[i].size();
        if(Deg[i] % 2 )
        Odd_Deg++;
    }
    // 1, 3, ,4 , 5 ..
    if(Odd_Deg != 2 && Odd_Deg != 0)
    return 0; 
    
    vector<bool>visited(V, 0);
    
    for(int i = 0; i < V; i++)
    {
        if(Deg[i]) 
        {
            DFS(i, adj , visited);
            break;
        }
    }
    // if any non 0 degree node is not visited - return 0
    // they are not a part of same component 
    
    // if any node have 0 degree ignore - since theree wont be any edge
    for(int i = 0; i < V; i++)
    {
        if(Deg[i] && !visited[i])
        return 0;
    }
    // if Eulerian circuit exist
        if(Odd_Deg == 0)
        return 2;
        else
        return 1; // Euler Path 
    }
};