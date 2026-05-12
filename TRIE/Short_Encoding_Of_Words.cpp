#include <bits/stdc++.h>
using namespace std;

// TC = O(N * 26) | SC = O(N * 26)

class TrieNode{
  public:
  TrieNode* child[26];

  TrieNode(){
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

  TrieNode* insert(string &s){
    TrieNode* cur = root;
    
    for(char &ch : s){
      int idx = ch - 'a';

      if(cur->child[idx] == NULL)
        cur->child[idx] = new TrieNode();

      cur = cur->child[idx];
    }    
    return cur;
  }
};

class Solution {
  public:
    bool isLeaf(TrieNode* node){
      for(int i = 0; i < 26; i++){
        if(node->child[i] != NULL){
          return false;
        }
      }
      return true;
    }

    int minimumLengthEncoding(vector<string>& words) {
    unordered_map<TrieNode*, int> m;
    Trie trie;

    for(auto &w : words){
      reverse(w.begin(), w.end());
    }    

    // Storing last referance node of word & wordLen
    // So that we can instantly check if its a leafNode then its Len contributes to ans
    for(auto &w : words){
      TrieNode* node = trie.insert(w);
      m[node] = w.size(); 
    }

    int ans = 0;
    for(auto &[node, len] : m){
      if(isLeaf(node)){
        ans += (len + 1);
      }
    }

    return ans;
  }
};