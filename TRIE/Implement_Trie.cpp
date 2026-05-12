#include <bits/stdc++.h>
using namespace std;

/* 
Overall : 
TC = O(N * L) | SC = O(N * L * 26) => O(N * L)
Where N = number of words | L = length of words
*/

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
    
    void insert(string word) { // TC = O(L) | SC = O(L*26) => O(L) space
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

      cur->isEnd = true; // Whole word insert, set isEnd = True
    }
    
    bool search(string word) { // TC = O(L) | SC = O(1)
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
    
    bool startsWith(string prefix) { // TC = O(L) | SC = O(1)
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