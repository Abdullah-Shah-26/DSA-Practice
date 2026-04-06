class Solution {
    public:  // TC= O(9^ empty cells) since we hsve 9 choices for each cell 
    //! logic to find safe cell
    bool isSafe(vector<vector<char>> &board, int row, int col, char dig){
        //horizontal check - col changes
        for(int j=0; j<9; j++){
            if(board[row][j] == dig){//same dig exist in row 
                return false;
            }
        }
        //vertical check - row changes
        for(int i = 0; i<9; i++){
            if(board[i][col] == dig){//same dig exist in col return false
                return false;

            }
        }
        // to check in grid sr sc - starting row & col of grid always multiples of 3
        int srow = (row/3) *3 ;
        int scol = (col/3) *3 ;

        //TC of loop = const 9 times small grid = O(1)
        for(int i = srow; i<= srow+2; i++){
            for(int j= scol; j<= scol+2; j++){
                if(board[i][j] == dig){ //same dig exist in grid return false
                    return false;
                }
            }
        }
        return true; //safe to place dig
    }



    //! making helper func since we are given 2 parameters only
    bool helper(vector<vector<char>> &board, int row, int col){
        //! BASE CASE
        if(row == 9){ //row has been filled 
            return true;
        } 

        // traversing all cells of a row
    int nextRow = row, nextCol = col+1;
    if(nextCol == 9){  // all cells of row traveresed
        nextRow = row+1;  //update row
        nextCol = 0; // starting next row with first cell
    } 
    if(board[row][col] != '.'){//a dig is already placed
        return helper(board, nextRow, nextCol);
    }
    //PLACING THE DIG
    for(char dig = '1' ;dig<= '9' ; dig++){
        if(isSafe(board, row, col, dig)){ //fun to check if its safe to place a dig
            board[row][col] = dig;
            if(helper(board, nextRow, nextCol)){ //recursive call to place dig in next row  
                return true;
            }
            board[row][col] = '.'; //backtracking step
        }
    }
    return false;// No valid placement found
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};
