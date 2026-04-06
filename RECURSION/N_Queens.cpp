#include<iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
//! part 2  ---> TC = O(n)
//* Func to check the safe positions of Queens 
bool isSafe(vector<string> &board, int row, int col,int n){  //! all these func will check if any other queen
    //! exist horizontally , vertically or diagonally return false if it exist

    //! horizontal check -> same row diff col
    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }
     //! vertical check -> diff row same col
     for(int i=0; i<n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    //! left diagonal check  (↖ direction)
    for(int i = row,j = col; i>=0 && j>=0; i--,j--){
        if(board[i][j] =='Q'){
            return false;
        }
    }
    //! right diagonal check (↗ direction)
    for(int i=row,j=col; i>=0 && j>=0; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
 return true; // Safe to place a queen if all 4 are false
}

//! part 1
void nQueens(vector<string> &board, int row, int n , vector<vector<string>> &ans){
//base case 
if(row == n){
    ans.push_back({board}); //*storing all possible board configurations ->ans
    return; 
}

        for(int j=0; j<n; j++){// to check possible positions of queen
            if(isSafe(board, row, j, n)){ // func to check safe positions of queen
                board[row][j] = 'Q'; //* place a Queen 
                nQueens(board, row+1, n, ans);
                board[row][j] = '.'; //!jab vapas backtrack karke aayenge we will place a dot 
                //!ab vaha se Queen ko hata diya hay and explore other options
            }    
        }
    }

vector<vector<string>> solveQueens(int n){ //*1 string represent 1 row of the board
    vector<string> board(n, string(n, '.')); //*board ka initialization where . indicate empty cell
    vector<vector<string>> ans;

    nQueens(board, 0, n, ans);
    return ans;


}
};
//! Since we explore N! possible board configurations, and each call checks O(N) safety, the worst-case time complexity is:
//! overall TC = O(N!⋅N) ≈ O(N!)