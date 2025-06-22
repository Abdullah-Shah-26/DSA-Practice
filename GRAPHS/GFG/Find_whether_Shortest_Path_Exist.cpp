#include <queue>
using namespace std;
//! BFS - METHOD
class Solution {
  public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
    
    bool valid(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
  
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        // Find the starting point (1) and push it into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0; // Mark as visited
                    break;
                }
            }
        }

        // Perform BFS
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int new_i = i + row[k];
                int new_j = j + col[k];

                // Check if the neighbor is valid
                if (valid(new_i, new_j, n)) {
                    if (grid[new_i][new_j] == 2) {
                        // Destination is found
                        return true;
                    }

                    if (grid[new_i][new_j] == 3) {
                        // Push valid path cell into the queue and mark as visited
                        grid[new_i][new_j] = 0;
                        q.push({new_i, new_j});
                    }
                }
            }
        }

        // If no path is found, return false
        return false;
    }
};
// ! DFS - METHOD
class Solution {
  public:
  bool dfs(vector<vector<int>>&grid, int x, int y)
  
  {
      // base case

    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
      return false;
      
      if(grid[x][y] == 2)
      return true;
      
      // mark as viisted
      grid[x][y] = 0;
      
      // and reculsively call dfs 
      return dfs(grid,x+1,y) || dfs(grid, x-1,y) || dfs(grid, x, y+1) || dfs(grid, x, y-1);
  }
  
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {// starting point
                
                return dfs(grid, i , j); // call dfs funtion
                break;
                    
                }
                    
                }
        }
        return false;
        
    }
};  