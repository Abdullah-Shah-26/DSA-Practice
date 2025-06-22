class Solution {
  public:
  
void DFS(int node, int parent , vector<int> adj[],vector<bool> &visited,  vector<int> &disc,vector<int> &low, vector<bool> &artpoint, int &timer )
{
    // mark node as visited
    visited[node] = 1;
    disc[node] = low[node] = timer;
    int child = 0 ;
    
    for(int j = 0; j< adj[node].size(); j++)
    {
        int neig = adj[node][j];
        
        if(neig == parent)
        continue;
        
        //neighbour is already visited
        else if(visited[neig])
        {
            low[node] = min(low[node] , disc[neig]);
        }
        else // not visited - visit karlo  and call dfs
        {
            child++;
            timer++;
            DFS(neig, node, adj , visited, disc, low, artpoint, timer);
            
            // while returning 
            ///// backtracking check if its an articulation pt
            if(disc[node] <= low[neig] && parent != -1)
        {
            artpoint[node] = 1; // its an articulation pt
        }
         low[node] = min(low[node] , low[neig]); // update its low 
        }
    }
    if(child > 1 && parent == -1) // root node/ starting node - edge case handling  
    {
        artpoint[node] = 1;
    }
    
}

    vector<int> articulationPoints(int V, vector<int> adj[]) {
      /// Tarjans Algorithm
      vector<bool>artpoint(V, 0);
      vector<int>disc(V); // discovery arr - 
      vector<int>low(V); // it shows the lowest reachable node a node can reach 
      vector<bool>visited(V,0);
      int timer = 0;
      
      DFS(0, -1, adj, visited, disc , low, artpoint, timer);
      
      vector<int>ans;
      
      for(int i = 0; i< V;i++)
      {
          if(artpoint[i])
          ans.push_back(i);
      }
        
    if(ans.size() == 0)
    ans.push_back(-1);
        
        return ans;
    }
};