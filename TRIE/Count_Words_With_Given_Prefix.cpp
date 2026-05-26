#include <bits/stdc++.h>
using namespace std;

class TrieNode{
  public:
  int cnt;
  TrieNode* child[26];

  TrieNode(){
    cnt = 0;
    for(int i = 0; i < 26; i++)
      child[i] = NULL;
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
      int i = ch - 'a';

      if(cur->child[i] == NULL)
        cur->child[i] = new TrieNode();

      cur = cur->child[i];
      cur->cnt++;
    }
  }

  int countPrefix(string &s){
    TrieNode* cur = root;
    
    for(char &ch : s){
      int i = ch - 'a';

      if(cur->child[i] == NULL)
        return 0;

      cur = cur->child[i];
    }
    return cur->cnt;
  }

};

class Solution {
  public:
  
  int prefixCount(vector<string>& words, string pref) {
  Trie trie;

  for(auto &s : words)
    trie.insert(s);

  return trie.countPrefix(pref);
  }
};