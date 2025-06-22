 class Solution { // TC = O(N^2) SC = O(N^2)
  // Knight can move in 8 directions
  public:
  int row[8] = {2, 2, -2, -2, 1, -1, 1, -1};
  int col[8] = {1, -1, 1, -1,2, 2, -2, -2 };
  
  bool valid(int i , int j , int n)
  {
      return i >= 0 && j >= 0 && i < n && j < n;
  }
  
  
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N){
        // Given 1 based Indexing make it 0 based else it will lead to segmentation fault
        KnightPos[0]--;
        KnightPos[1]--;
        TargetPos[0]--;
        TargetPos[1]--;
        
    // base cases - Think before hand 
    // if the target and curr pos are already same
    if(TargetPos[0] == KnightPos[0] && TargetPos[1] == KnightPos[1])
    return 0;
    
        
        // Simple B F S 
        queue<pair<int, int>>q;
        vector<vector<bool>>chess(N, vector<bool>(N, 0));
        
        q.push({KnightPos[0], KnightPos[1]});
        chess[KnightPos[0]][KnightPos[1]] = 1; // mark as visited
        
        int step = 0;
        while(!q.empty())
        {
            int count = q.size();
            while(count--)
            {
                int i = q.front().first;
                int j = q.front().second;
                
                q.pop();
                
                // all the postitions we can go
                for(int k = 0 ; k < 8 ; k++ )
                {
                    int new_i = i + row[k];
                    int new_j = j + col[k];
                    
                    // check if new pos is valid & isnt already visited
                    if(valid(new_i, new_j, N) && !chess[new_i][new_j])
                    {
                        // Check if knight reached the target
                        if(new_i == TargetPos[0] && new_j == TargetPos[1])
                        return step + 1;
                        
                        chess[new_i][new_j] = 1;
                        q.push({new_i, new_j});
                    }
                }
                }
            step++;
            }
        return -1;
        }
   
    
};