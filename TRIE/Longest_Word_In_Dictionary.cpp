#include <bits/stdc++.h>
using namespace std;

// TC = O(N * L) | SC = O(N * L)
// Trie + DFS + BackTracking

class TrieNode{
  public:
  TrieNode* child[26];
  bool isEnd;

  TrieNode(){
    isEnd = false;
    for(int i = 0; i < 26; i++){
      child[i] = NULL;
    }
  }
};

class Trie{
  private: 
  TrieNode* root;
  
  public:
  Trie(){
    root = new TrieNode();
  }

  void insert(string word){
    TrieNode* cur = root;
    for(char &ch : word){
      int idx = ch - 'a';

      if(cur->child[idx] == NULL){
        cur->child[idx] = new TrieNode();
      }
      cur = cur->child[idx];
    }
    cur->isEnd = true;
  }

  TrieNode* getRoot(){
    return root;
  }
};

class Solution {
  public:
    void dfs(TrieNode* node, string &cur, string &ans){
      if(ans.size() < cur.size()){
        ans = cur;
      }

      for(int i = 0; i < 26; i++){
         TrieNode* next = node->child[i];

        if((next != NULL) && (next->isEnd == true)){
          cur.push_back(i + 'a');

          dfs(node->child[i], cur, ans);
          
          cur.pop_back();
        }
      }
    }

    string longestWord(vector<string>& words) {
    Trie trie;

    for(string &s : words){
      trie.insert(s);
    }

    string cur = "";
    string ans = "";

    dfs(trie.getRoot(), cur, ans);

    return ans;
    }
};