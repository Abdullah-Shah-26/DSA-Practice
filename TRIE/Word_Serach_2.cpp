#include <bits/stdc++.h>
using namespace std;

// TC = O(No of words * Len of each word) + O(N*M) * 3^(Len of word) 
// -> Since we cannot go back to prev character so at each pos we have 3 directions * L depth of trie (Max Word Len)  
// -> In Worst Case all 3^L characters form a word.

class TrieNode{
  public:
  TrieNode* child[26];
  string word;

  TrieNode(){
    word = "";
    for(int i = 0; i < 26; i++){
      child[i] = NULL;
    }
  }
};

class Trie{
  private : 
  TrieNode* root; 
  
  public:
  Trie(){
    root = new TrieNode();
  }

  void insert(string &s){
    TrieNode* cur = root;

    for(char &ch : s){
      int idx = ch - 'a';

      if(cur->child[idx] == NULL){
        cur->child[idx] = new TrieNode();
      }
      cur = cur->child[idx];
    }
    cur->word = s;  
  }

  TrieNode* getRoot(){
    return root;
  }
};

class Solution {
  public:
    Trie trie;
    int n,m;
    vector<string> ans;

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    void dfs(int r, int c, vector<vector<char>> &board, TrieNode* node){
      if(r < 0 || r >= n || c < 0 || c >= m) return; 
      if(board[r][c] == '#') return;
      
      char ch = board[r][c];
      if(node->child[ch - 'a'] == NULL) return;

      node = node->child[ch - 'a'];

      if(node->word != ""){
        ans.push_back(node->word); // Word Found, push in ans
        node->word = ""; // Avoid duplicates
      }

      board[r][c] = '#'; // Mark as visited

      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];
        dfs(nr, nc, board, node);
      }

      board[r][c] = ch; // backtracking 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    n = board.size();
    m = board[0].size();   

    TrieNode* root = trie.getRoot();
    
    for(auto &s : words){
      trie.insert(s);
    }

    for(int r = 0; r < n; r++){
      for(int c = 0; c < m; c++){
        dfs(r, c, board, root);
      }
    }

    return ans;
    }
};