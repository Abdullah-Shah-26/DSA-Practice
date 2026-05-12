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

class Trie {
  private:
  TrieNode* root;

  public:
    Trie() {
      root = new TrieNode();
    }
    
    void insert(string word) {
      TrieNode* cur = root;

      for(char ch : word){
        int idx = ch - 'a';

        // create if missing
        if(cur->child[idx] == NULL){
          cur->child[idx] = new TrieNode();
        }

        // else keep moving forward
        cur = cur->child[idx];
      }  

      cur->isEnd = true; 
    }
    
    bool search(string word) {
      TrieNode* cur = root;

      for(char ch : word){
        int idx = ch - 'a';

        if(cur->child[idx] == NULL){
          return false;
        }

        cur = cur->child[idx];
      }

      return cur->isEnd; // We found all chars & word ended then isEnd = True
    }
    
    bool startsWith(string prefix) {
      TrieNode* cur = root;

      for(char ch : prefix){
        int idx = ch - 'a';

        if(cur->child[idx] == NULL){
          return false;
        }

        cur = cur->child[idx];
      }

      return true; // We have found the prefix
    }
};