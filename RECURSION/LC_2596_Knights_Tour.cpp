class Solution {
    public: //! TC = O(8^ (n^2)) -> n^2 cells and each has 8 choices
            // SC = O(n^2)   -- recursive call stack
        bool isvalid(vector<vector<int>>& grid, int r, int c, int n, int expval){
            //! we are using expected value to track where we have to move from all possible moves
            //* like 0 -> 1 -> 2            not 0 -> 7 even if its possible
    
    
            //! check if grid r and c are valid -- and if next cell is not equal to expval return false
                if(r<0 || c<0 || r>=n || c>=n || grid[r][c]!= expval) {
                    return false;
               }
                //! if we reached last cell return true 
               if(expval == n*n-1){
                return true;
               }
    
    
               //8 possible moves 
               int ans1 = isvalid (grid, r-2, c+1, n, expval+1);
               int ans2 = isvalid (grid, r-1, c+2, n, expval+1);
               int ans3 = isvalid (grid, r+1, c+2, n, expval+1);
               int ans4 = isvalid (grid, r+2, c+1, n, expval+1);
               int ans5 = isvalid (grid, r+2, c-1, n, expval+1);
               int ans6 = isvalid (grid, r+1, c-2, n, expval+1);
               int ans7 = isvalid (grid, r-1, c-2, n, expval+1);
               int ans8 = isvalid (grid, r-2, c-1, n, expval+1);
            
            // kahi se bhi true aaya eg:  0-1,0-7 so return tue
            return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
        }
        bool checkValidGrid(vector<vector<int>>& grid) { 
                 return isvalid(grid, 0, 0, grid.size(), 0);
        }
    
    };