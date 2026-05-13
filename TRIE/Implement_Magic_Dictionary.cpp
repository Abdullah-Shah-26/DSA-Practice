#include <bits/stdc++.h>
using namespace std;

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

  void insert(string &s){
    TrieNode* cur = root;

    for(char &ch : s){
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

class MagicDictionary {
  public:
    Trie trie;

    bool dfs(int i, string &s, TrieNode* node, bool changed){
      if(i == s.size()){
        return node->isEnd && changed; 
      }

      char ch = s[i];

      // Option 1 : Keep same char
      if(node->child[ch-'a'] != NULL){
        if(dfs(i + 1, s, node->child[ch - 'a'], changed))
          return true;
      }
      // Option 2 : Modify 1 char if possible
      for(int j = 0; j < 26; j++){
        // Dont modify char to same char
        if(j != ch-'a' && node->child[j] != NULL && changed == false){
          if(dfs(i + 1, s, node->child[j], true)){
            return true;
          }
        }
      }
    return false;
    }

    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dict) { // O(N * L)
      for(string &s : dict){
        trie.insert(s);
      }  
    } 
    
    bool search(string searchWord) { // O(L * 26)
      return dfs(0, searchWord, trie.getRoot(), false); 
    }
};
