#include <bits/stdc++.h>
using namespace std;

// DFS on Trie

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

class WordDictionary {
public:
    Trie trie;

    bool dfs(int i, TrieNode* node, string &s){
      if(i == s.size()) return node->isEnd;

      char ch = s[i];

      if(ch != '.'){
       if(node->child[ch - 'a'] == NULL) 
        return false;

       return dfs(i + 1, node->child[ch - 'a'], s);
      }

      // else
      for(int j = 0; j < 26; j++){
        if(node->child[j] != NULL){
          if(dfs(i + 1, node->child[j], s)){
            return true;
          }
        }
      }
    return false;
    }

    WordDictionary() {
    }
    
    void addWord(string word) { // TC = O(L) | SC = O(L)
      trie.insert(word); 
    }
    
    bool search(string word) { 
      // Worst Case  : '...........' so // TC = O(26 ^ L) 
      return dfs(0, trie.getRoot(), word);        
    }
};
