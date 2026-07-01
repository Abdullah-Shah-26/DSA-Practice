#include <bits/stdc++.h>
using namespace std;

//! TC = O(4^(n^2))   // n square cell each cell has 4 choices ////✅ Worst-case space complexity: O(n²) (due to recursion depth).
void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans){
    // base case 
    int n = mat.size();
    //first check if row or col is valid || avoid ) cells || avoid already visited cells
    if(r<0 || c<0 || r>=n || c>=n || mat[r][c] == 0|| mat[r][c] == -1){
    return;
}
if(r == n-1 && c == n-1){ // reached end cell 
    ans.push_back(path); // store ansswers
    return;
}
    //! for tracking visited cells
    mat[r][c] = -1; // mark as visited cell

    // 4 directions - 4 rec calls
    helper(mat, r+1, c, path+"D",ans); //down
    helper(mat, r-1, c, path+"U",ans); //up
    helper(mat, r, c-1, path+"L",ans); //left
    helper(mat, r, c+1, path+"R",ans); //right

    mat[r][c] = 1; //! backtracking _ unvisit -> to explore all variations -> unmark the cell

}

//complete this function
vector<string> findPath(vector<vector<int>> &mat){
    vector<string>ans;
    string path ="";
  //! Start the recursion from the top-left corner 1st cell
    helper(mat , 0, 0, path, ans); 
    return ans;
}
int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = findPath(mat);

    // Print all the paths
    for (const string &p : paths) {
        cout << p << endl;
    }

    return 0;
}
    