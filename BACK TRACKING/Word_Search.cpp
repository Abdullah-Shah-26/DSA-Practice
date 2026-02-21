class Solution {
public:
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};
    int n, m;

    bool find(int i,int j,int idx,vector<vector<char>>&board, string &word)
    {
      if(idx == word.size()) return true;
      if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '$')
      return false;

      if(board[i][j] != word[idx])
      return false;

      char temp = board[i][j];
      board[i][j] = '$';

      for(int k = 0; k < 4; k++)
      {
        int nr = i + row[k];
        int nc = j + col[k];

        if(find(nr,nc,idx+1,board,word)) return true;
      }
      board[i][j] = temp;

      return false;
    }

    bool exist(vector<vector<char>>& board, string word)  {
     n = board.size();
     m = board[0].size();
    for(int i = 0;i < n; i++)
    {
      for(int j = 0;j < m; j++)
      {
        if(board[i][j] == word[0] && find(i,j,0,board,word)) return true;
      }
    } 
    return false;   
    }
};